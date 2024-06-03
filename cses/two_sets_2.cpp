#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

using namespace std;

/*
dp[i][j] = number of ways to get sum j using first i numbers
dp[i][j] = dp[i - 1][j] + dp[i - 1][j - i]
*/
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n;
    cin >> n;
    int sum = n / 2 * (n + 1);

    if (sum % 2 != 0)
        cout << 0 << endl;
    else
    {
        sum /= 2;
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= i)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % MOD;
            }
        }
        cout << dp[n][sum] << endl;
    }
}