#include <iostream>
#include <vector>
#define pair pair<int, int>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<int> &dp, int node, int parent){
    for (auto i : adj[node]){
        if (i != parent){
            dfs(adj, dp, i, node);
            dp[node] = max(1 + dp[i], dp[node]);
        }
    }
}

void dfs2(vector<vector<int>> &adj, vector<vector<int>> &dp, vector<int> &toleaf, int node, int parent){
    for (auto i : adj[node]){
        if (i != parent){
            dp[i][0] = toleaf[parent] + 1;
        }
    }
}

int main(){
#ifdef LOCAL_TESTING
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n; cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> toleaf(n + 1, 0); // stores max length from node x to any leaf
    dfs(adj, toleaf, 1, -1); // root tree arbitrarily

    vector<vector<int>> maxlen(n + 1, vector<int>(2, 0)); // stores 2 max lengths through its parent
    dfs2(adj, maxlen, toleaf, 1, -1);
}
