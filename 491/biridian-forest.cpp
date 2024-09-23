#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>
#define pii pair<int, int>
using namespace std;

int main(){
    #ifdef LOCAL_TESTING
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
    #endif
    std::cin.tie(nullptr); // Break the tie between cin and cout

    int r, c; cin >> r >> c;
    vector<vector<char>> graph(r, vector<char>(c));
    pii exit, start;
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            cin >> graph[i][j];
            if (graph[i][j] == 'E') exit = {i, j};
        }
    }

    vector<pii> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    queue<pii> q;
    q.push(exit);
    graph[exit.first][exit.second] = 'T';
    int total = 0;
    while(!q.empty()){
        int round = q.size();
        bool startfound = false;
        while(round--){
            const auto [x, y] = q.front(); q.pop();
            for (auto &[dx, dy] : dirs){
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < r && ny >= 0 && ny < c && graph[nx][ny] != 'T'){
                    if (graph[nx][ny] == 'S') startfound = true;
                    else total += graph[nx][ny] - '0';
                    // cout << graph[nx][ny] << endl;
                    graph[nx][ny] = 'T';
                    q.push({nx, ny});
                }
            }
        }
        if (startfound) break;
    }
    cout << total << endl;
}
