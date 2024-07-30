#include <iostream>
#include <ostream>
#include <vector>
#include <queue>
#define pair pair<int, int>
using namespace std;

int dfs(vector<vector<int>> &adj, vector<int> &visited, int cur){
    for (auto &n : adj[cur]) {
        if (visited[n] && visited[cur] != n) {
            visited[n] = cur;
            return n;
        }
        if (visited[n] == 0) {
            visited[n] = cur;
            dfs(adj, visited, n);
        }
    }
    return -1;
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
            visited[i] = -1;
            int res = dfs(adj, visited, i);
            if (res != -1){
                int cur = visited[res];
                while (cur != res){
                    cout << cur << endl;
                    cur = visited[cur];
                }
                cout << res;
                return 0;
            }
        }
    }

    // for (int i = 1; i <= n; ++i){
    //     cout << visited[i] << endl;
    // }
    cout << "IMPOSSIBLE" << endl;
}
