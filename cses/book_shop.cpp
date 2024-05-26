#include <iostream>
#include <vector>
const int mod = 1e9 + 7;

using namespace std;

/*
find max num pages
dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - prices[i - 1]] + pages[i - 1]);
*/
int main()
{
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int n, x;
    cin >> n >> x;

    int prices[n], pages[n];
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0)); // dp[i][j] = max pages with i books and j money

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= prices[i - 1])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - prices[i - 1]] + pages[i - 1]);
            }
        }
    }

    cout << dp[n][x] << endl;
}