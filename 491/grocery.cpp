#include <iostream>
#include <vector>
#define ll long long
using namespace std;
const ll INF = 1e18;

int main(){
    #ifdef LOCAL_TESTING
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<pair<int, ll>> items(n);
    for (int i = 0; i < n; ++i){
        cin >> items[i].first >> items[i].second;
    }

    vector<ll> dp(n + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < n; ++i){
        int s = 1 + items[i].first;
        ll c = items[i].second;

        for (int k = n; k >= 0; --k){
            if (dp[k] < INF){
                int k_new = min(k + s, n);
                if (dp[k_new] > dp[k] + c){
                    dp[k_new] = dp[k] + c;
                }
            }
        }
    }

    cout << dp[n] << endl;

}
