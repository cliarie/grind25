#include <iostream>
#include <vector>
#define ll long long

const int mod = 1e9 + 7;

using namespace std;

/*
dp[i][j] = number of arrays with arr[i] = j
*/
int main()
{
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    ll n, m;
    cin >> n >> m;

    ll arr[n];
    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    vector<vector<ll>> dp(n, vector<ll>(m + 1, 0));

    if (arr[0] == 0)
    {
        for (ll j = 1; j <= m; j++)
            dp[0][j] = 1;
    }
    else
        dp[0][arr[0]] = 1;

    for (ll i = 1; i < n; i++)
    {
        if (arr[i] == 0)
        {
            for (ll j = 1; j <= m; j++)
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % mod;
        }
        else
            dp[i][arr[i]] = (dp[i - 1][arr[i] - 1] + dp[i - 1][arr[i]] + dp[i - 1][arr[i] + 1]) % mod;
    }
    ll ans = 0;
    for (ll j = 1; j <= m; j++)
        ans = (ans + dp[n - 1][j]) % mod;

    cout << ans << endl;
}