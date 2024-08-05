#include <vector>
using namespace std;
class Solution {
public:
    int getrep(vector<int>& dsu, int i){
        while (i != dsu[i]){
            i = dsu[i];
        }
        return i;
    }

    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> dsu(m*n, -1);
        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<int> ans;
        int islands = 0;
        for (auto &pos : positions){
            int r = pos[0], c = pos[1];
            int i = r*n+c;
            if (dsu[i] == -1) {
            dsu[i] = i;
            islands++;
            for (auto &d : dirs){
                int nr = r + d.first, nc = c + d.second;
                int ni = nr*n + nc;
                if (nr >= 0 && nc >= 0 && nr < m && nc < n && dsu[ni] != -1){
                    int other = getrep(dsu, ni);
                    if (other != dsu[i]){
                        dsu[other] = i;
                        //dsu[i] = other;
                        islands--;
                    }
                }
            }}
            ans.push_back(islands);
        }
    return ans;
    }
};
