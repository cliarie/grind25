class Solution
{
public:
    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        map<int, int> m;
        for (auto i : intervals)
        {
            m[i[0]]++;
            m[i[1]]--;
        }
        int cur = 0, res = 0;
        for (auto i : m)
        {
            cur += i.second;
            res = max(res, cur);
        }
        return res;
    }
};

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<double, int>> intervallist;
        for (int i = 0; i < intervals.size(); ++i){
            intervallist.push_back({intervals[i][0], i});
            intervallist.push_back({intervals[i][1] - 0.5, i});
        }
        sort(intervallist.begin(), intervallist.end());

        int rooms = 0, cur = 0;
        vector<int> visited(intervals.size());
        for (auto interval : intervallist){
            if (!visited[interval.second]){
                cur++;
                visited[interval.second] = 1;
            } else{
                cur--;
            }
            cout << interval.first << " " << interval.second << " " << cur << endl;
            rooms = max(rooms, cur);
        }
        return rooms;
    }
};
