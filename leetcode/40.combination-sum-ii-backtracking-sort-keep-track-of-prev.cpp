class Solution {
public:
    int target;
    vector<int> candidates;
    vector<vector<int>> result;

    void backtrack(vector<int> &curcand, int cursum, int index){
        if (cursum == target) {
            result.push_back(curcand);
            return;
        }
        int prev = -1;
        for (int i = index; i < candidates.size(); ++i){
            if (cursum + candidates[i] > target) break;
            if (prev == candidates[i]) continue;
            curcand.push_back(candidates[i]);
            backtrack(curcand, cursum + candidates[i], i + 1);
            curcand.pop_back();
            prev = candidates[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this->target = target;
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;

        vector<int> cur;
        backtrack(cur, 0, 0);

        return result;

    }
};
