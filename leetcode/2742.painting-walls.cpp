#include <vector>
using namespace std;

class Solution
{
public:
    int paintWalls(vector<int> &cost, vector<int> &free)
    {
        /*
        " There is a sale in a super market. If you buy an item for cost[i]. you can get free[i] items as free. Return the minimum amount you need to spend to get all the required items."
        */

        int n = cost.size();

        vector<int> dp(n + 1, 1e9); // min cost for i items
        dp[0] = 0;                  // 0 cost to get 0 items

        for (int i = 0; i < n; ++i)
        {
            // for each item, decide whether or not to buy item i: will cost[i], but will give you free[i] + 1 (what you bought)
            // populate all possibilities for this decision for all items before moving on to make a decision for another item
            for (int j = n; j >= 0; --j)
            {   // reverse order or messes up don't buy option
                // for (int j = 0; j <= n; ++j){ // in order messes up not buying choice
                if ((j - free[i] - 1) >= 0)
                    dp[j] = min(dp[j], dp[j - free[i] - 1] + cost[i]);
                else
                    dp[j] = min(dp[j], dp[0] + cost[i]);
                for (auto x : dp)
                    cout << x << " ";
                cout << endl;
            }
        }

        return dp[n];
    }
};