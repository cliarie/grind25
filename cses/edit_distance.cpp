#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
dp[i][j] = minimum number of operations to convert a[0..i] to b[0..j]
dp[i][j] = min(dp[i - 1][j - 1] + (a[i] != b[j]), dp[i - 1][j] + 1, dp[i][j - 1] + 1)

Insert: dp[i][j] = dp[i - 1][j] + 1
Delete: dp[i][j] = dp[i][j - 1] + 1
Replace: dp[i][j] = dp[i - 1][j - 1] + (a[i] != b[j])

Base case:
dp[0][0] = 0
dp[i][0] = i
dp[0][j] = j

Answer:
dp[n][m]

Time complexity: O(n * m)

Space complexity: O(n * m)

n: length of a
m: length of b
*/

int main()
{
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
        dp[i][0] = i;
    for (int j = 1; j <= m; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]));
        }
    }

    cout << dp[n][m] << endl;
}