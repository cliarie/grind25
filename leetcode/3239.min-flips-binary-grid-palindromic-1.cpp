class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        // dp
        int n = grid.size(), m = grid[0].size();
        vector<int> dpr(m + 1), dpc(n + 1);

        int rc = 0, cc = 0;
        for (int i = 0; i < n; ++i){
            int l = 0, r = m - 1;
            while (r > l){
            if (grid[i][l] != grid[i][r]) rc++;
            l++; r--;}
        }
        for (int i = 0; i < m; ++i){
            int l = 0, r = n - 1;
            while (r > l){
            if (grid[l][i] != grid[r][i]) cc++;
            l++; r--;}
        }
        // cout << min(rc, cc) << endl;
        return min(rc, cc);
    }
};
