#include <iostream>
#include <vector>
#define pair pair<int, int>
using namespace std;

void getheight(vector<vector<int>> &adj, vector<int> &dp, int node, int parent){
    for (auto i : adj[node]){
        if (i != parent){
            getheight(adj, dp, i, node);
            dp[node] = max(dp[node], 1 + dp[i]);
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

    int l = 0;
    for (int i = 1; i <= n; ++i){
        vector<int> dp(n + 1, 0);
        if (adj[i].size() == 1){
            getheight(adj, dp, i, -1);
            l = max(dp[i], l);
        }
    }
    cout << l << endl;
    // for (int i = 1; i <= n; ++i) cout << i << " " << dp[i] << endl;

    // int max1 = 0, max2 = 0;
    // for (auto i : adj[1]){
    //     if (dp[i] > max1) max1 = dp[i];
    //     else if (dp[i] > max2) max2 = dp[i];
    // }

    // cout << 2 + max1 + max2 << endl;
}
