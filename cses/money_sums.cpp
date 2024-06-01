#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
dp[i] = true if sum can be formed
dp[i] = dp[i - coins[j]] for j = 0 to n
*/
int main()
{
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    int n, maxcoins = 0;
    cin >> n;
    int coins[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> coins[i];
        maxcoins += coins[i];
    }

    vector<bool> dp(maxcoins + 1, false);
    dp[0] = true;
    set<int> sums;

    for (int j = 0; j < n; ++j)
    {
        for (int i = maxcoins; i >= 0; --i)
        {
            if (i - coins[j] >= 0 && dp[i - coins[j]])
            {
                dp[i] = true;
                sums.insert(i);
            }
        }
    }
    cout << sums.size() << endl;
    for (int sum : sums)
        cout << sum << " ";
}