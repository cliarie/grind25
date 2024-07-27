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