#include <vector>
using namespace std;
class Solution {
public:
    const int INF = 1e9;
    int minDistance(vector<int>& houses, int kt) {
        // med minimizes dist
        int n = houses.size();
        sort(houses.begin(), houses.end());

        // total dist if place mailbox at med of i, j
        vector<vector<int>> tdist(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                int med = (i + j) / 2;
                for (int k = i; k <= j; ++k)
                    tdist[i][j] += abs(houses[med] - houses[k]);
            }
        }

        vector<vector<int>> dp(n, vector<int>(kt + 1, INF));
        for (int i = 0; i < n; ++i) dp[i][1] = tdist[0][i];

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < i; ++j){
                for (int k = 2; k <= kt; ++k){
                    dp[i][k] = min(dp[i][k], dp[j][k - 1] + tdist[j + 1][i]);
                }
            }
        }

        return dp[n - 1][kt];
    }
};
