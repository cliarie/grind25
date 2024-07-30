#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    struct job {
        int start, end, profit;
        bool operator<(const job &other) const {
            return end < other.end;
        }
    };
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
        int n = startTime.size();
        vector<job> arr(n + 1);
        for (int i = 1; i <= n; ++i) {
            arr[i] = {startTime[i - 1], endTime[i - 1], profit[i - 1]};
        }
        sort(arr.begin(), arr.end());

        vector<int> dp(n + 1, 0);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            // find prev where end <= current start
            job j = {0, arr[i].start, 0};
            auto it = prev(upper_bound(arr.begin(), arr.begin() + i, j));
            int idx = it - arr.begin();
            idx = max(idx, 0);
            dp[i] = max(dp[i - 1], dp[idx] + arr[i].profit);
        }
        return dp[n];
    }
};
