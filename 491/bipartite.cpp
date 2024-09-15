#include <iostream>
#include <vector>
#include <queue>
#define ll long long
using namespace std;

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    int n; cin >> n;

    vector<int> vis(n, 0);
    vector<vector<int>> graph(n);
    for (int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    ll v1 = 1, v2 = 0;
    while(!q.empty()){
        int v = q.front(); q.pop();
        for (int n : graph[v]){
            if (vis[n]==0){
                q.push(n);
                vis[n] = -1 * vis[v];
                if (vis[n] == 1) v1++;
                else v2++;
            }
        }
    }
    ll ans = v1 * v2 - (n - 1);
    cout << max(0LL, ans) << endl;
    // cout << max(0, (((n*n) / 4) - (n - 1))) << endl;
}
