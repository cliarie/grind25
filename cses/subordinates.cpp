#include <iostream>
#include <vector>
#include <map>
using namespace std;

void dfs(vector<vector<int>> &adj, int start, vector<int> &count){
    // count[start]++;
    for (auto i : adj[start]){
        dfs(adj, i, count);
        count[start]+=count[i]+1;
    }
}
int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int n; cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; ++i){
        int m; cin >> m;
        // cout << m << i << endl;
        adj[m].push_back(i);
    }

    vector<int> sub(n + 1, 0);
    dfs(adj, 1, sub);
    for (int i = 1; i <= n; ++i) cout << sub[i] << " ";
    // for (int i = 1; i <= n; ++i){
    //     int count = 0;

    //     cout << count << " ";
    // }
}
