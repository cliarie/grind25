#include <iostream>
#include <vector>
#define ll long long
const int mod = 1e9 + 7;

using namespace std;

/*
solve(x) = 0 if x < 0
solve(x) = 1 if x = 0
solve(x) = solve(x - coin[0]) + solve(x - coin[1]) + ... + solve(x - coin[n - 1]) if x > 0
*/

int main()
{
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int n;
    ll x;
    cin >> n >> x;
    ll coin[n];
    for (int i = 0; i < n; i++)
        cin >> coin[i];

    vector<ll> dp(x + 1, 0);
    dp[0] = 1;

    for (int j = 0; j < n; j++)
    {
        for (int i = 1; i <= x; i++)
        {
            if (i - coin[j] >= 0)
                dp[i] = (dp[i] + dp[i - coin[j]]) % mod;
        }
    }

    cout << dp[x];
}