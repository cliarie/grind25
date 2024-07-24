class Solution {
public:
    bool isok(vector<vector<int>> &board, int r, int c){
        // check nothing in diag, row, col
        // check something can be put in rest of rows

        int n = board.size();
        for (int i = 0; i <= r; ++i){ // i>row checked in dfs
            if (board[i][c]) return false;
            if ((r - i >=0 && c - i >=0) && board[r - i][c - i]) return false;
            if ((r - i >=0 && c + i <n) && board[r - i][c + i]) return false;
        }
        return true;
    }
    int dfs(vector<vector<int>> &board, int r){
        if (r == board.size()) return 1;
        int count = 0;
        for (int c = 0; c < board.size(); ++c){
            if (isok(board, r, c)){
                board[r][c] = 1;
                count += dfs(board, r + 1);
                board[r][c] = 0;
            }
        }
        return count;
    }
    int totalNQueens(int n) {
       // feel like there exists some deterministic sol ? idk maybe it's np hard
       vector<vector<int>> board(n, vector<int>(n));
       return dfs(board, 0);
    }
};
