#include <iostream>
#include <vector>
#define ll long long
using namespace std;

/*
solve(0) = 0
solve(1) = 1
solve(2) = 2
solve(3) = 1
solve(4) = 1
solve(5) = 2
solve(6) = 2
solve(7) = 2
solve(8) = 2
solve(9) = 3
solve(10) = 3

solve(x) = min(solve(x − 1) + 1, solve(x − 3) + 1, solve(x − 4) + 1)

solve(x) = inf if x < 0
solve(x) = 0 if x = 0
solve(x) = min(solve(x-coins[i]) + 1) if x > 0
*/

int main()
{
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int n, x;
    std::cin >> n >> x;
    int coins[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> coins[i];
    }

    vector<int> dp(x + 1, INT_MAX); // min coins to make sum x;
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - coins[j] >= 0)
                dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
        }
    }
    if (dp[x] == INT_MAX)
        cout << -1 << endl;
    else
        cout << dp[x] << endl;
}