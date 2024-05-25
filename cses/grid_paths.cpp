#include <iostream>
#include <vector>
const int mod = 1e9 + 7;

using namespace std;

int main()
{
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;

    char grid[n][n];
    vector<vector<int>> dp(n, vector<int>(n, 0)); // number of paths from start to (i, j)

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (int c = 0; c < n; c++)
    {
        if (grid[0][c] == '*')
            break;
        dp[0][c] = 1;
    }

    for (int r = 0; r < n; r++)
    {
        if (grid[r][0] == '*')
            break;
        dp[r][0] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (grid[i][j] == '*')
                continue;
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[n - 1][n - 1] << endl;
}