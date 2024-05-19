#include <iostream>
#include <vector>
#define ll long long
const ll inf = 1e9;
const ll mod = 1e9 + 7;

using namespace std;

/*
solve(x) =solve(x − 1)+ solve(x − 3)+ solve(x − 4)
solve(x) = 0 if x < 0
solve(x) = 1 if x = 0
solve(x) = summation of (solve(x - c)) if x > 0
*/

int main()
{
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int n;
    cin >> n;
    ll x, coin[n];
    cin >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }

    vector<ll> dp(x + 1, 0); // number of ways to make sum x;
    dp[0] = 1;
    for (ll i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - coin[j] >= 0)
                dp[i] = (dp[i] + dp[i - coin[j]]) % mod;
        }
    }
    cout << dp[x];
}