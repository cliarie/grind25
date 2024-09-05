#include <iostream>
#include <vector>
using namespace std;

bool isok(vector<vector<int> > &board, int r, int c){
    for (int i = 0; i <= r; ++i){
        if (board[i][c]) return false; // check prev row
        if (r - i >= 0 && c - i >= 0 && board[r - i][c - i]) return false;
        if (r - i >= 0 && c + i < board[0].size() && board[r - i][c + i]) return false;
    }
    return true;
}

int dfs(vector<vector<int> > &board, int row, int k){
    if (k == 0) return 1;
    if (row == board.size()) return 0;
    int count = 0;
    for (int c = 0; c < board[0].size(); ++c){
        //cout << row << " " << c << " " << k << endl;
        if (isok(board, row, c)){
            board[row][c] = 1;
            count += dfs(board, row + 1, k - 1);
            board[row][c] = 0;
        }
    }
    count += dfs(board, row + 1, k);
    return count;
}

int nqueens(int k, int n, int m){
    vector<vector<int> > board(n, vector<int>(m));
    return dfs(board, 0, k);
}

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    int k, n, m;
    cin >> k >> n >> m;
    cout << nqueens(k, n, m);
}
