#include <map>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        map<int, set<int>> dp;
        dp[stones[0] + 1] = {1}; // can get to dp[] from #'s in set
        for (int i = 1; i < n; ++i){
            for (auto k : dp[stones[i]]){
                dp[stones[i] + k].insert(k);
                dp[stones[i] + k - 1].insert(k - 1);
                dp[stones[i] + k + 1].insert(k + 1);
            }
        }

        return (dp[stones[n - 1]].size() != 0);
    }
};
