#include <iostream>
#include <vector>
using namespace std;

int main(){
    #ifdef LOCAL_TESTING
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];

        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; ++i){
            dp[i] = a[i];
        }

        for (int i = n; i >= 1; --i){
            if (i + a[i] <= n)
                dp[i] = dp[i] + dp[i + a[i]];
        }
        // for (int i = n; i >= 1; --i){
        //     for (int j = i + a[i]; j <= n; j += a[j]){
        //         dp[i] = max(dp[i], dp[j] + a[i]);
        //     }
        // }

        cout << *max_element(dp.begin(), dp.end()) << endl;

    }
}
