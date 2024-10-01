class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size() - 1;
        for (int i = 0; i < (n + 1) / 2; ++i){
            for (int j = 0; j < (n + 2) / 2; ++j){
                vector<int> old = {matrix[i][j], matrix[j][n - i], matrix[n-i][n-j], matrix[n-j][i]};
                matrix[j][n - i] = old[0];
                matrix[n - i][n - j] = old[1];
                matrix[n - j][i] = old[2];
                matrix[i][j] = old[3];
            }
        }
    }
};
