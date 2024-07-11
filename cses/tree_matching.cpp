#include <iostream>
#include <vector>
#define pair pair<int, int>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<vector<int>>& dp, int node, int parent){
    for (auto i : adj[node]){
        if (i != parent){
            dfs(adj, dp, i, node);
            dp[node][0] += max(dp[i][1], dp[i][0]);
            // cout << "don't choose " << node << " " << dp[node][0] << endl;
        }
    }

    for (auto i : adj[node]){
        if (i != parent){
            dp[node][1] = max(dp[node][1], 1 + dp[i][0] + dp[node][0] - max(dp[i][0], dp[i][1]));
            // cout << "choose " << node << " " << dp[node][1] << endl;
        }
    }
}

int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int n; cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // 2d dp
    vector<vector<int>> dp(n + 1, vector<int> (2, 0));

    dfs(adj, dp, 1, 0);

    // for (int i = 1; i <= n; ++i) cout << dp[i][0] << " " << dp[i][1] << endl;

    cout << max(dp[1][0], dp[1][1]) << endl;
}
