#include <iostream>
#include <vector>

const int inf = 1e9;

using namespace std;

/*
dp[i][j] = minimum cuts to cut i x j rectangle
dp[i][j] = min(dp[i][j-k] + dp[i][k] + 1, dp[i-k][j] + dp[k][j] + 1) for k = 1 to i-1
dp[i][j] = 0 if i = 1 and j = 1

*/
int main()
{
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, inf)); // minimum cuts to cut axb rectangle

    dp[1][1] = 0;
    for (int i = 1; i <= a; ++i)
    {
        for (int j = 1; j <= b; ++j)
        {
            if (i == j)
            {
                dp[i][j] = 0;
                continue;
            }
            for (int k = 1; k < i; ++k)
                dp[i][j] = min(dp[i - k][j] + dp[k][j] + 1, dp[i][j]);
            for (int k = 1; k < j; ++k)
                dp[i][j] = min(dp[i][j - k] + dp[i][k] + 1, dp[i][j]);
        }
    }

    // for (int i = 1; i <= a; ++i)
    // {
    //     for (int j = 1; j <= b; ++j)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    cout << dp[a][b] << endl;
}