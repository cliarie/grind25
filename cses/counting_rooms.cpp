#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;

void bfs(vector<vector<char>>& matrix, int i, int j){
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty()){
        auto cur = q.front();
        q.pop();
        for (auto d : dirs){
            int x = cur.first + d.first;
            int y = cur.second + d.second;
            if (x >= 0 && y >= 0 && x < n && y < m && matrix[x][y] == '.') {
                matrix[x][y] = '#';
                q.push({x, y});
            }
        }
    }
}

void dfs(vector<vector<char>> &matrix, int i, int j){
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    matrix[i][j] = '#';
    for (auto d : dirs){
        int x = i + d.first;
        int y = j + d.second;
        if (x >= 0 && y >= 0 && x < n && y < m && matrix[x][y] == '.') {
            dfs(matrix, x, y);
        }
    }
}

int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    cin >> n >> m;
    vector<vector<char>> matrix(n, vector<char>(m, '.'));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == '.') {
                bfs(matrix, i, j);
                count++;
            }
        }
    }
    cout << count << endl;
}
