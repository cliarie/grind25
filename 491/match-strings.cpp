#include <iostream>
#include <vector>
#include <string>
#define ll long long
using namespace std;

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    std::cin.tie(nullptr); // Break the tie between cin and cout

    string source, dest; cin >> source >> dest;
    int n; cin >> n;
    vector<vector<ll>> dist(26, vector<ll>(26, INT_MAX));

    if (source.length() != dest.length()) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < n; ++i){
        char a, b; ll c; cin >> a >> b >> c;
        int u = a - 'a', v = b - 'a';
        dist[u][v] = min(dist[u][v], c);
    }

    // floyd warshall for k (0, n); for i (0, n); for j (0, n); dist[i][j] = mina(dist[i][j], dist[i][k] + dist[k][j])
    // source: i, dest: j, intermediate: k
    for (int i = 0; i < 26; ++i) dist[i][i] = 0;

    for (int k = 0; k < 26; ++k){
        for (int i = 0; i < 26; ++i){
            for (int j = 0; j < 26; ++j){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    string ans = source;
    ll total = 0;
    for (int i = 0; i < source.length(); ++i){
        int u = source[i] - 'a', v = dest[i] - 'a';
        if (u != v){
            ll mincost = INT_MAX;
            int best = u;

            for (int j = 0; j < 26; ++j){
                if (dist[u][j] + dist[v][j] < mincost){
                    mincost = dist[u][j] + dist[v][j];
                    best = j;
                }
            }

            if (mincost == INT_MAX){
                cout << -1 << endl;
                return 0;
            }

            total += mincost;
            ans[i] = (char)('a' + best);
        }
    }

    cout << total << endl;
    cout << ans << endl;
}
