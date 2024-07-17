#include <vector>
#include <queue>
#include <map>
using namespace std;
class Solution
{
public:
    bool inbounds(int x, int y, int n, int m)
    {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
    {
        int n = grid.size();
        int m = grid[0].size();
        int k = queries.size();

        multimap<int, int> sortedq; // QUERIES NOT DISTINCT
        for (int i = 0; i < k; ++i)
        {
            sortedq.insert({queries[i], i});
        }

        vector<int> path;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, std::greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});

        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        vector<vector<int>> visited(n, vector<int>(m, 0));
        visited[0][0] = 1;
        while (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();

            int val = cur.first;
            int x = cur.second.first;
            int y = cur.second.second;
            // cout << val << " " << x << " " << y << endl;

            path.push_back(val);

            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dirs[i].first;
                int ny = y + dirs[i].second;
                if (inbounds(nx, ny, n, m) && !visited[nx][ny])
                {
                    int nval = grid[nx][ny];
                    visited[nx][ny] = 1;
                    pq.push({nval, {nx, ny}});
                }
            }
        }

        vector<int> ans(k, 0);
        int count = 0;
        auto it = sortedq.begin();
        for (int i = 0; i < path.size(); it != sortedq.end())
        {
            // cout << path[i] << endl;
            if (it->first > path[i])
            {
                count++;
                i++;
            }
            else
            {
                ans[it->second] = count;
                it++;
            }
            if (it == sortedq.end())
                break;
        }

        while (it != sortedq.end())
        {
            ans[it->second] = count;
            it++;
        }
        return ans;
    }
};