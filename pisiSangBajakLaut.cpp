#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N, K;
vector<int> treasure;                
vector<vector<int>> tree;            
int maxTreasure = 0;                 


void dfs(int node, int parent, int currentTreasure) {

    if (currentTreasure > K) {
        return;
    }

    maxTreasure = max(maxTreasure, currentTreasure);
    

    for (int neighbor : tree[node]) {
        if (neighbor != parent) {

            dfs(neighbor, node, currentTreasure + treasure[neighbor]);
        }
    }
}

int main() {

    cin >> N;
    
    treasure.resize(N); 
    tree.resize(N);     
    

    for (int i = 0; i < N; i++) {
        cin >> treasure[i];
    }
    

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--; 
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    

    cin >> K;
    

    dfs(0, -1, treasure[0]);
    
    cout << maxTreasure << endl;
    
    return 0;
}
