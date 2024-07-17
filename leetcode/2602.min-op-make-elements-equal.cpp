#include <vector>
using namespace std;
class Solution
{
public:
    vector<long long> minOperations(vector<int> &nums, vector<int> &queries)
    {
        long long n = nums.size();
        sort(nums.begin(), nums.end());

        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; ++i)
        {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        vector<long long> ans;
        for (auto q : queries)
        {
            long long amt = 0;
            auto itg = upper_bound(nums.begin(), nums.end(), q);
            if (itg != nums.end())
            {
                int idxg = itg - nums.begin();
                long long greater = (idxg > 0) ? prefix[n - 1] - prefix[idxg - 1] : prefix[n - 1];
                long long count = n - idxg;
                amt += greater - q * count;
            }

            auto itl = lower_bound(nums.begin(), nums.end(), q);
            if (itl != nums.begin())
            {
                int idxl = itl - nums.begin();
                long long lesser = (idxl > 0) ? prefix[idxl - 1] : 0;
                long long count = idxl;
                amt += q * count - lesser;
            }

            ans.push_back(amt);
        }
        return ans;
    }
};