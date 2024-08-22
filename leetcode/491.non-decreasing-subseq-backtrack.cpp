#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    set<vector<int>> ans;

    void dfs(vector<int> &cur, int i, vector<int>& nums){
        if (i == nums.size()){
            if (cur.size() > 1) ans.insert(cur);
            return;
        }
        if (cur.empty() || cur.back() <= nums[i]){
            cur.push_back(nums[i]);
            dfs(cur, i + 1, nums);
            cur.pop_back();
        }
        dfs(cur, i + 1, nums);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> t;
        dfs(t, 0, nums);

        vector<vector<int>> res;
        for (auto s : ans) res.push_back(s);
        return res;
    }
};
