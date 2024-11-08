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

    string s, t; cin >> s >> t;
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; ++i){
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; ++j){
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s[i - 1] != t[j - 1]));
        }
    }

    cout << dp[n][m] << endl;

}
