class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty()) return res;
        int start = nums[0], end = nums[0];
        for (int i = 1; i < nums.size(); ++i){
            cout << start << " " << end << " " << nums[i] << endl;
            if (nums[i] == (end + 1)) {
                end = nums[i];
            }
            else{
                string s = (start == end) ? to_string(start) : to_string(start) + "->" + to_string(end);
                res.push_back(s);
                start = nums[i];
                end = nums[i];
            }
        }
        string s = (start == end) ? to_string(start) : to_string(start) + "->" + to_string(end);
        res.push_back(s);
        return res;
    }
};
