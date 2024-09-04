class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<vector<int>> row(n, vector<int>(n)), col(n, vector<int>(n)), square(n, vector<int>(n));
        vector<vector<int>> nums;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (board[i][j] != '.'){ 
                    int t = board[i][j] - '0' - 1;
                    cout << t << endl;
                    if (row[i][t]++) return false;
                    if (col[j][t]++) return false;
                    if (square[i/3 * 3 + j / 3][t]++) return false;
                }
            }
        }
        return true;
    }
};
