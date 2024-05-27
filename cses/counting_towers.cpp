#include <iostream>
#define ll long long
const int mod = 1e9 + 7;
using namespace std;

int main()
{
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll dp[n + 1][2]; // dp[i][j] = number of ways to build a tower of height i; j is either type 1 tower or type 2 tower
        dp[1][0] = 1;    // 1 way to build tower (height 1) with 2 blocks width 1 at top
        dp[1][1] = 1;    // 1 way to build tower (height 1) with 1 block width 2 at top
        for (int i = 2; i <= n; i++)
        {
            dp[i][0] = (dp[i - 1][0] * 4 + dp[i - 1][1]) % mod;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] * 2) % mod;
        }
        cout << (dp[n][0] + dp[n][1]) % mod << endl;
    }
}