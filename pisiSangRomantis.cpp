#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;


struct State {
    int x, y, time;
};

int dx[4] = {0, -1, 0, 1}; 
int dy[4] = {-1, 0, 1, 0}; 


int getGhostDirection(int initial_value, int t) {
    return 1 + (initial_value + t - 1) % 4;
}


bool isGhostInCell(int x, int y, int t, const vector<vector<int>>& grid, int N, int M) {
    int initial_value = grid[x][y];
    if (initial_value == 0) return false; 

    int direction = getGhostDirection(initial_value, t);

    int new_x = x, new_y = y;
    if (direction == 1) new_y--;     
    else if (direction == 2) new_x--; 
    else if (direction == 3) new_y++; 
    else if (direction == 4) new_x++; 

    if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= M) return false;
    
    return (new_x == x && new_y == y);
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> grid(N, vector<int>(M)); 
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
        }
    }

    queue<State> q;
    q.push({0, 0, 0}); 
    
    vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(1001, false)));
    visited[0][0][0] = true;

    while (!q.empty()) {
        State cur = q.front();
        q.pop();
        
        int x = cur.x, y = cur.y, time = cur.time;
        
        if (x == N - 1 && y == M - 1) {
            cout << time << endl;
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny][time + 1]) {
                if (!isGhostInCell(nx, ny, time + 1, grid, N, M)) {
                    visited[nx][ny][time + 1] = true;
                    q.push({nx, ny, time + 1});
                }
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
