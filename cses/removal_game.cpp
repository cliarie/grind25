#include <iostream>
#include <vector>
#define ll long long

using namespace std;

/*

dp[i][j] = maximum difference between the scores of the players
dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1])
let dp[i][j] = player1 - player2
then dp[i + 1][j] = player2 - player1
or dp[i][j - 1] = player2 - player1

A = (A + B + (A - B)) / 2
answer: dp[0][n - 1] + (sum of all inputs) / 2
*/
int main()
{
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    for (int i = n - 1; i >= 0; --i) // dp[i][j] depends on dp[i + 1][j] and dp[i][j - 1], so we start from the end (larger i)
    {
        for (int j = i; j < n; ++j) // right has to be bigger than left
        {
            if (i == j)
                dp[i][j] = a[i];
            else
                // swap players
                dp[i][j] = max(-dp[i + 1][j] + a[i], -dp[i][j - 1] + a[j]);
        }
    }
    ll total = 0;
    for (int i = 0; i < n; i++)
        total += a[i];
    cout << (dp[0][n - 1] + total) / 2 << endl;
}