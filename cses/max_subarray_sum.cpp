#include <iostream>
#include <vector>
const int NEGINF = -1e9;
using namespace std;

int main(){
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    vector<int> dp(n + 1, NEGINF);
    int ans = NEGINF;
    dp[0] = arr[0];
    for (int i = 1; i <= n; ++i){
        dp[i] = max(arr[i], dp[i - 1] + arr[i]);
        ans = max(ans, dp[i]);
    }
    // for (int i = 0; i <= n; ++i) cout << dp[i] << " " ;
    // cout << endl;
    cout << ans << endl;
}
