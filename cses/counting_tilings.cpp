#include <iostream>
#include <vector>

using namespace std;

/*
dp[i][j] = ways to fill grid of size i x j
dp[i - 1][j] = last row filled with 1 x 2 tiles
dp[i][j - 1] = last column filled with 2 x 1 tiles
dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
*/
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(m, 0));
}