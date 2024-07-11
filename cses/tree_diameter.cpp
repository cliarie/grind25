#include <iostream>
#include <vector>
#define pair pair<int, int>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<int> &dp, int node, int parent){
    for (auto i : adj[node]){
        if (i != parent){
            dp[i] = 1 + dp[node];
            dfs(adj, dp, i, node);
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

    vector<int> dp(n + 1, 0);
    dfs(adj, dp, 1, -1);

    pair farthest = {1, 0};
    for (int i = 1; i <= n; ++i){
        if (dp[i] > farthest.second) farthest = {i, dp[i]};
    }

    vector<int> dp2(n + 1, 0);
    dfs(adj, dp2, farthest.first, -1);

    farthest.second = 0;
    for (int i = 1; i <= n; ++i){
        if (dp2[i] > farthest.second) farthest = {i, dp2[i]};
    }

    cout << farthest.second << endl;
}
