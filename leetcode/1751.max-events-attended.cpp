#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [](auto &left, auto &right){
            return left[1] < right[1];
        }); // sort based on end times

        for (auto i : events) cout << i[0] << " " << i[1] << " " << i[2] << endl;

        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 1; i <= n; ++i){
            vector<int> start = {0, events[i - 1][0], 0};
            auto it = lower_bound(events.begin(), events.begin() + i, start, [](auto &left, auto &right){return left[1] < right[1];});
            int p;
            if (it == events.end()) p = 0;
            else p = prev(it) - events.begin() + 1;
            //p = max(p, 0); // find last event before i could go to
            cout << i << " " << p << " k" << events[i - 1][1] << endl;
            for (int j = 1; j <= k; ++j){
                dp[i][j] = max(dp[i - 1][j], dp[p][j - 1] + events[i - 1][2]);
            }
        }
        return dp[n][k];
    }
};
