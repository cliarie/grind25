#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main(){
    #ifdef LOCAL_TESTING
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    ll n; cin >> n;
    vector<vector<ll>> dist(n, vector<ll>(n));

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> dist[i][j];
        }
    }

    vector<ll> removed(n);
    for (int i = 0; i < n; ++i){
        cin >> removed[i];
        removed[i]--;
    }

    vector<ll> ans(n), visited(n);
    for (int i = n - 1; i >= 0; --i){
        // go in reverse order, sequentially adding nodes
        visited[removed[i]] = 1;
        ll sum = 0;

        for (int k = 0; k < n; ++k){
            for (int j = 0; j < n; ++j){
                dist[k][j] = min(dist[k][j], dist[k][removed[i]] + dist[removed[i]][j]);
            }
        }

        for (int k = 0; k < n; ++k){
            for (int j = 0; j < n; ++j){
                if (visited[k] && visited[j]) sum += dist[k][j];
            }
        }
        ans[i] = sum;
    }

    for (auto node : ans) cout << node << " ";
    cout << endl;
}
