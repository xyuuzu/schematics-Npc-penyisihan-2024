#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>

using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1}; 

bool is_valid(int x, int y, int N, int M) {
    return x >= 1 && x <= N && y >= 1 && y <= M;
}

vector<vector<int>> bfs(int start_x, int start_y, int N, int M) {
    vector<vector<int>> dist(N + 1, vector<int>(M + 1, INT_MAX));
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    dist[start_x][start_y] = 0;
    
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        int current_dist = dist[x][y];
        
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (is_valid(nx, ny, N, M) && dist[nx][ny] == INT_MAX) {
                dist[nx][ny] = current_dist + 1;
                q.push({nx, ny});
            }
        }
    }
    return dist;
}

int simulate_game(int N, int M, pair<int, int> pisi_start, pair<int, int> elsi_start, char first_turn) {
    vector<vector<int>> pisi_dist = bfs(pisi_start.first, pisi_start.second, N, M);
    vector<vector<int>> elsi_dist = bfs(elsi_start.first, elsi_start.second, N, M);

    int min_moves = INT_MAX;
    vector<vector<vector<vector<int>>>> dp(N + 1, vector<vector<int>>(M + 1, vector<vector<int>>(N + 1, vector<int>(M + 1, INT_MAX))));
    dp[pisi_start.first][pisi_start.second][elsi_start.first][elsi_start.second] = 0;

    queue<tuple<int, int, int, int, bool>> q;
    q.push(make_tuple(pisi_start.first, pisi_start.second, elsi_start.first, elsi_start.second, first_turn == 'P'));

    while (!q.empty()) {
        auto [px, py, ex, ey, is_pisi_turn] = q.front(); q.pop();
        int current_moves = dp[px][py][ex][ey];

        if (px == ex && py == ey) {
            min_moves = min(min_moves, current_moves);
            continue;
        }

        if (is_pisi_turn) {
            for (int i = 0; i < 4; ++i) {
                int nx = px + dx[i];
                int ny = py + dy[i];
                if (is_valid(nx, ny, N, M) && dp[nx][ny][ex][ey] == INT_MAX) {
                    dp[nx][ny][ex][ey] = current_moves + 1;
                    q.push(make_tuple(nx, ny, ex, ey, false));
                }
            }
        } else {
            for (int i = 0; i < 4; ++i) {
                int nx = ex + dx[i];
                int ny = ey + dy[i];
                if (is_valid(nx, ny, N, M) && dp[px][py][nx][ny] == INT_MAX) {
                    dp[px][py][nx][ny] = current_moves + 1;
                    q.push(make_tuple(px, py, nx, ny, true));
                }
            }
        }
    }
    
    return min_moves == INT_MAX ? 0 : min_moves;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    int Pi, Pj, Ei, Ej;
    cin >> Pi >> Pj >> Ei >> Ej;
    
    char C;
    cin >> C;
    
    pair<int, int> pisi_start = {Pi, Pj};
    pair<int, int> elsi_start = {Ei, Ej};
    
    int result = simulate_game(N, M, pisi_start, elsi_start, C);
    cout << result << endl;
    
    return 0;
}
