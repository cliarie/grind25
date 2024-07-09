#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> &adj, int n){
    vector<int> visited(n + 1, 0);
    queue<int> q;
    q.push(1);
    visited[1] = -1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for (auto i : adj[cur]){

            if (visited[i] == 0){
                visited[i] = cur;
                if (i == n) {
                    int t = n;
                    vector<int> ans; ans.push_back(n);
                    while(visited[t] != -1){
                        t = visited[t];
                        ans.push_back(t);
                    }
                    reverse(ans.begin(), ans.end());
                    cout << ans.size() << endl;
                    for (auto i : ans) cout << i << " ";
                    return;
                }
                q.push(i);

            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}

int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(adj, n);

}
