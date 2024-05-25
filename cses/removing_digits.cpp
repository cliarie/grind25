#include <iostream>
#include <vector>

#define ll long long
const int inf = 1e9;

using namespace std;

/*
solve(x) = min(solve(x - d) + 1) for all digits d in x
*/

int main()
{
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    ll n;
    cin >> n;

    vector<ll> dp(n + 1, inf); // dp[i] = minimum number of steps to reach i
    dp[0] = 0;

    for (ll i = 1; i <= n; i++)
    {
        ll temp = i;
        while (temp > 0)
        {
            int digit = temp % 10;
            dp[i] = min(dp[i], 1 + dp[i - digit]);
            temp /= 10;
        }
    }

    cout << dp[n];
}