class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int ones = 0;
        for (auto i : grid){
            for (auto j : i) if (j == 1) ones++;
        }
        
        // backtracking? ones % 4 eq 0
        int c = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < (n)/2; ++i){
            for (int j = 0; j < (m)/2; ++j){
                // if (i != 0 && i == j) {
                //     c += grid[i][j];
                //     cout << grid[i][j];
                //     continue;
                // }
                int allz = 0, tflip = 0;

                allz += grid[i][j]; tflip++;

                if (((m-1) - j) != j) {
                    allz += grid[i][(m-1) - j];
                    tflip++;
                }
                if (((n-1) - i) != i) {
                    allz += grid[(n-1) - i][j];
                    tflip++;
                }
                if (((m-1) - j) != j && ((n-1) - i) != i) {
                    allz += grid[(n-1) - i][(m-1) - j];
                    tflip++;
                }
                cout << allz << endl;
                //allz += (grid[i][j] + grid[i][(m-1) - j] + grid[(n-1) - i][j] + grid[(n-1) - i][(m-1) - j]);
                if (tflip != 4) c += allz;
                else c += min(allz, tflip - allz);
            }
        }

        // traverse remaining row/col separately
        int match = 0, nmatch = 0;
        if (n%2 == 1){
            int allz = 0;
            for (int i = 0; i < m/2; ++i){
                if (grid[n/2][i] != grid[n/2][(m-1) - i]){
                    nmatch++;
                    c++;
                }
                else if (grid[n/2][i] == 1) match++;
            }
        }

        if (m%2 == 1){
            int allz = 0;
            for (int i = 0; i < n/2; ++i){
                if (grid[i][m/2] != grid[(n-1) - i][m/2]){
                    nmatch++;
                    c++;
                }
                else if (grid[i][m/2] == 1) match++;
            }
        }

        if (match%2==1 && !nmatch) c += 2;
        if (n%2==1 && m%2==1) c += grid[n/2][m/2];

        return c;
    }
};
