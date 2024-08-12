#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        vector<pair<int, int>> coord; // {x1/2, building};
        for (int i = 0; i < n; ++i){
            coord.push_back({buildings[i][0], i});
            coord.push_back({buildings[i][1], i});
        }
        sort(coord.begin(), coord.end());
        priority_queue<pair<int, int>> present; // height, right edge

        vector<vector<int>> ans;
        int i = 0;
        while (i < coord.size()){
            int cur = coord[i].first;
            while(i < coord.size() && coord[i].first == cur){
                if (buildings[coord[i].second][0] == cur){
                    present.push({buildings[coord[i].second][2], buildings[coord[i].second][1]});
                }
                i++;
            }

            while(!present.empty() && present.top().second <= cur){
                present.pop();
            }


            int newh = 0;
            if (!present.empty()) newh = present.top().first;

            if (ans.empty() || newh != ans[ans.size()-1][1]) ans.push_back({cur, newh});
        }
        return ans;
    }
};
