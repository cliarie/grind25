#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int n, m;

void bfs(vector<vector<char>>& matrix, int i, int j){
    vector<pair<char, pair<int, int>>> dirs = {{'R', {0, 1}}, {'D', {1, 0}}, {'L', {0, -1}}, {'U', {-1, 0}}};

    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty()){
        auto cur = q.front();
        q.pop();
        for (auto d : dirs){
            int x = cur.first + d.second.first;
            int y = cur.second + d.second.second;
            if (x >= 0 && y >= 0 && x < n && y < m && (matrix[x][y] == '.' || matrix[x][y] == 'B')) {
                if (matrix[x][y] == 'B') {
                    matrix[x][y] = d.first;
                    return;
                }
                matrix[x][y] = d.first;
                q.push({x, y});
            }
        }
    }
}

void dfs(vector<vector<char>> &matrix, int i, int j){

    vector<pair<char, pair<int, int>>> dirs = {{'R', {0, 1}}, {'D', {1, 0}}, {'L', {0, -1}}, {'U', {-1, 0}}};

    // matrix[i][j] = '#';
    for (auto d : dirs){
        int x = i + d.second.first;
        int y = j + d.second.second;
        if (x >= 0 && y >= 0 && x < n && y < m && (matrix[x][y] == '.' || matrix[x][y] == 'B')) {
            if (matrix[x][y] == 'B') {
                matrix[x][y] = d.first;
                return;
            }
            matrix[x][y] = d.first;
            dfs(matrix, x, y);
        }
    }
}

int main(){
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    cin >> n >> m;
    pair<int, int> a, b;
    vector<vector<char>> matrix(n, vector<char>(m, '.'));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'A'){
                a.first = i; a.second = j;
            }
            else if (matrix[i][j] == 'B'){
                b.first = i; b.second = j;
            }
        }
    }

    int count = 0;
    string ans = "";
    bfs(matrix, a.first, a.second);

    // for (int i = 0; i < n; ++i){
    //     for (int j = 0; j < m; ++j) cout << matrix[i][j] << " " ;
    //     cout << endl;
    // }

    map<char, pair<int, int>> dirs = {{'L', {0, 1}}, {'U', {1, 0}}, {'R', {0, -1}}, {'D', {-1, 0}}};
    int x = b.first; int y = b.second;
    if (matrix[x][y] == 'B'){
        cout << "NO" <<endl;
        return 0;
    }
    while (matrix[x][y] != 'A'){
        count++;
        ans += matrix[x][y];
        int temp = x + dirs[matrix[x][y]].first;
        y+=dirs[matrix[x][y]].second;
        x = temp;
    }
    reverse(ans.begin(), ans.end());
    cout << "YES" << endl;
    cout << count << endl;
    cout << ans << endl;
}
