#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        // dp[i] = set of unique numbers that is the result of or-ing subarrays up to i
        // dp[i] = {i | (everything in dp[i - 1])}
        // O(n * max bits in largest num)
        int n = arr.size();
        vector<set<int>> dp(n + 1);

        set<int> res;
        for (int i = 0; i < n; ++i){
            set<int> cur;
            cur.insert(arr[i]);
            res.insert(arr[i]);
            if (i > 0) {
                for (auto &s : dp[i - 1]){
                    cur.insert(arr[i] | s);
                    res.insert(arr[i] | s);
                }
            }
            dp[i] = cur;
        }

        return res.size();

    }
};
