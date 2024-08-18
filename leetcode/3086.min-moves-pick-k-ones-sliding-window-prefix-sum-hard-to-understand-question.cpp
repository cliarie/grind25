#include <vector>
using namespace std;

#define ll long long
class Solution {
public:
    long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
        // op1 : set y next to alice index, pick; cost 2
        // op2 : swap y until equals alice index; cost dist |y-x|
        // use op1 unless adj indices (cost = 1)

        int n = nums.size();
        vector<ll> dist = {0};
        for (int i = 0; i < n; ++i)
            if (nums[i])
                dist.push_back(dist[dist.size() - 1] + i); // calc sum of dist

        ll op2min = max(0, k - maxChanges);

        ll dn = dist.size();
        ll op2max = min((ll)k, min(op2min + 3, dn - 1));
        // max at most op2min + 3 (2 adjacent is, 1 cur i)
        // max <= number of ones, amt of ones needed

        ll ans = 1e15;

        for (ll i = op2min; i <= op2max; ++i){
            for (ll j = 0; j < dn - i; ++j){
                ll end = j + i; // iterate through all possible windows of size op2min to op2max (i)
                ll mid1 = (j + end) / 2;
                ll mid2 = (j + end + 1) / 2;

                // use max of op2 possible
                ll cost = dist[end] - dist[mid2];
                cost -= dist[mid1] - dist[j];

                // use op1 which costs 2 for rest
                cost += (k - i) * 2;
                ans = min(ans, cost);
            }
        }
        return ans;
    }
};
