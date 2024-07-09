#include <iostream>
#include <vector>
#include <map>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int node){
    visited[node] = 1;
    for (int i : adj[node]){
        if (!visited[i]) dfs(adj, visited, i);
    }
}

int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int n, m; cin >> n >> m;
    vector<bool> visited(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int count = 0;
    vector<int> roads;
    for (int i = 1; i <= n; ++i){
        if (!visited[i]) {
            dfs(adj, visited, i);
            count++;
            roads.push_back(i);
        }
    }

    //for (auto i : roads) cout << i << endl;

    cout << count - 1<< endl;
    for (int i = 0; i < count - 1; ++i){
        cout << roads[i] << " " << roads[i + 1] << endl;
    }

}
