#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

vector<int> dr = {1, -1, 1, -1, -1, 1, 0, 0};
vector<int> dc = {1, -1, -1, 1, 0, 0, 1, -1};

int find(vector<string> &a, int row, int col){
    cout << row << " " << col << endl;
    int count = 0;
    for (int i = 0; i < 8; ++i){
        int nr = row + 3 * dr[i];
        int nc = col + 3 * dc[i];
        if (nr >= 0 && nr < a.size() && nc >= 0 && nc < a[0].size()){
            if (a[row + dr[i]][col + dc[i]] == 'M' &&
            a[row + 2 * dr[i]][col + 2 * dc[i]] == 'A' &&
            a[nr][nc] == 'S'
            ) count++;
        }
    }
    return count;
}

int part1(vector<string> &a){
    int count = 0;
    for (int i = 0; i < a.size(); ++i){
        for (int j = 0; j < a[0].size(); ++j){
            if (a[i][j] == 'X'){
                count += find(a, i, j);
            }
        }
    }
    return count;
}

int find2(vector<string> &a, int row, int col){
    int cm = 0, cs = 0;
    for (int i = 0; i < 4; ++i){
        int nr = row + dr[i];
        int nc = col + dc[i];
        if (nr >= 0 && nr < a.size() && nc >= 0 && nc < a[0].size()){
            if (a[nr][nc] == 'M') cm++;
            if (a[nr][nc] == 'S') cs++;
        }
    }
    if (cm == 2 && cs == 2 && a[row-1][col-1] != a[row+1][col+1]) return 1;
    return 0;
}

int part2(vector<string> &a){
    int count = 0;
    for (int i = 0; i < a.size(); ++i){
        for (int j = 0; j < a[0].size(); ++j){
            if (a[i][j] == 'A'){
                count += find2(a, i, j);
            }
        }
    }
    return count;
}

int main(){
    #ifdef LOCAL_TESTING
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string> a;
    string line;
    while(getline(cin, line)){
        a.push_back(line);
    }

    // cout << part1(a) << endl;
    cout << part2(a) << endl;

}
