#include <iomanip>
#include <vector>
#include <iostream>
#define ll long long
using namespace std;

// find nodes connected in each piece of graph
// k * (k - 1) / 2 points earn points, ans = # pairs can earn points / total pairs
int dfs(int node, vector<vector<int>> &graph, vector<bool> &vis){
    if (vis[node]) return 0;
    vis[node] = true;
    int res = 1;
    for (auto &next : graph[node]){
        res += dfs(next, graph, vis);
    }
    return res;
}

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<bool> vis(n, false);
    for (int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i){
        ll k = dfs(i, graph, vis);
        ans += k*(k -1)/2;
    }
    ll totalpairs = (ll) n * (n - 1) / 2;
    cout << setprecision(7) << (double) ans / totalpairs << endl;
}
