class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0], end = intervals[0][1];
        vector<vector<int>> ans;
        for (auto v : intervals){
            int first = v[0], second = v[1];
            cout << first << " " << second << " " << start << " " << end << endl;
            if (first <= end && second <= end) continue;
            else if (first <= end) end = second;
            else {
                ans.push_back({start, end});
                start = first;
                end = second;
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};
