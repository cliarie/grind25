#include <iostream>
#include <vector>
#define ll long long
#define INT_MAX 1e9
using namespace std;

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