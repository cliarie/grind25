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
        int k, d; string s;
        cin >> k >> d >> s;

        int n = s.size();
        vector<int> zeroes(n + 1, 0);
        zeroes[0] = (s[0] == '0');
        for (int i = 1; i < n; ++i) zeroes[i] = zeroes[i - 1] + (s[i] == '0');
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; ++i){
            for (int j = 0; j <= k; ++j){
                dp[i][j] = dp[i - 1][j];
                if (i >= d){
                    int zeroes_needed = zeroes[i - 1] - zeroes[i - d] + (s[i - d] == '0');
                    if (j >= zeroes_needed){
                        dp[i][j] = max(dp[i][j], dp[i-d][j-zeroes_needed] + 1);
                    }
                }
            }
        }

        cout << dp[n][k] << endl;
    }
}
