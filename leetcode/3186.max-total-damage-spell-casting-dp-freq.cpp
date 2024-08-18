#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<long long, long long> freq;
        for (auto p : power) freq[p]++;

        vector<pair<long long, long long>> arr;
        for (auto f : freq) arr.push_back(f);

        vector<long long> dp(arr.size());
        dp[0] = arr[0].first * arr[0].second;
        for (int i = 1; i < freq.size(); ++i){
            long long best = arr[i].first * arr[i].second;
            long long a = arr[i].first - arr[i - 1].first;
            if (a > 2) best += dp[i - 1];
            //cout << "first " << a << " " << best << endl;

            if (i > 1) {
                long long b = arr[i].first - arr[i - 2].first;
                if (b > 2 && best == arr[i].first * arr[i].second) best += dp[i - 2];
                //cout << "second " << b << " " << best << endl;
            }
            if (i > 2 && best == arr[i].first * arr[i].second) best += dp[i - 3];
            //cout << "fallback " << best << " " << endl;


            dp[i] = max(dp[i - 1], best);
        }
        //for (auto i : dp) cout << i << endl;
        return dp[arr.size() - 1];
    }
};
