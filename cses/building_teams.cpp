#include <iostream>
#include <vector>
#include <queue>
#define pair pair<int, int>
using namespace std;

int bfs(vector<vector<int>> &adj, vector<int> &visited, int i){
    queue<int> q;
    q.push(i);
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (auto &n : adj[cur]){
            if (visited[n] && visited[n] == visited[cur]) return -1;
            if (!visited[n]){
                visited[n] = (visited[cur] == 1) ? 2 : 1;
                q.push(n);
            }
        }
    }
    return 1;
}

int main(){
#ifdef LOCAL_TESTING
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> visited(n + 1, 0);

    for (int i = 1; i <= n; ++i){
        if (!visited[i]) {
            visited[i] = 1;
            if (bfs(adj, visited, i) == -1){
                cout << "IMPOSSIBLE" << endl; return 0;
            }
        }
    }

    for (int i = 1; i <= n; ++i){
        cout << visited[i] << endl;
    }

}
