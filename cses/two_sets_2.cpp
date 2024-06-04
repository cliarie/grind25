#include <iostream>
#include <vector>
#define ll long long
const int MOD = 1e9 + 7;

using namespace std;

/*
    Given a number n, we need to find the number of ways to divide the numbers 1 to n into two sets such that the sum of the numbers in both sets is equal.
    We can solve this problem using dynamic programming. Let dp[i][j] be the number of ways to divide the numbers 1 to i into two sets such that the sum of the numbers in both sets is j.
    We can calculate dp[i][j] using the following recurrence:
    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - i]
    The answer will be dp[n][sum / 2] where sum = n * (n + 1) / 2.
    Time complexity: O(n * sum)
*/
int main()
{
    // dp[i][j] = dp[i-1][j] + dp[i-1][j-i]
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int n;
    cin >> n;
    ll sum = (n * (n + 1)) / 2;

    if (sum % 2 != 0)
        cout << 0 << endl;
    else
    {
        sum /= 2;
        vector<vector<ll>> dp(n + 1, vector<ll>(sum + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j <= sum; ++j)
            {
                dp[i][j] = dp[i - 1][j];
                if (j - i >= 0)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % MOD;
            }
        }
        cout << dp[n - 1][sum] << endl; // permanently put n in one of the sets to accommodate for the two sets
        // cout << dp[n][sum] / 2 << endl; // divide by two to account for the two sets HOWEVER does not work since need modulo inverse ://
    }
}