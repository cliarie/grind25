#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct Node{
    int r, c;
    char mode;
    int cost, time;

    bool operator<(const Node &other) const{
        if (time == other.time) return cost < other.cost;
        return time < other.time;
    }
};

vector<int> dr = {0, 0, 1, -1}, dc = {1, -1, 0, 0};

tuple<char, int, int> bfs(vector<vector<char>> &grid, pair<int, int> start, unordered_map<char, int> &costs, unordered_map<char, int> &times){
    priority_queue<Node> q; // store the position, mode, time, cost
    Node start_node = {start.first, start.second, 'S', 0, 0};
    q.push(start_node);
    grid[start.first][start.second] = 'X';

    while(!q.empty()){
        Node cur = q.top();
        cout << "r: " << cur.r << ", c: " << cur.c << ", mode: " << cur.mode << ", cost: " << cur.cost << ", time: " << cur.time << endl;
        q.pop();

        if (cur.mode == 'D'){
            return {cur.mode, cur.cost, cur.time};
        }

        for (int i = 0; i < 4; ++i){
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            if (nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size() || grid[nr][nc] == 'X'){
                continue;
            }
            if (cur.mode == 'S' || cur.mode == grid[nr][nc] || grid[nr][nc] == 'D'){
                q.push({nr, nc, grid[nr][nc], cur.cost + costs[grid[nr][nc]], cur.time + times[grid[nr][nc]]});
                grid[nr][nc] = 'X';
            }
        }
    }
    return {'D', -1, -1};
}

int main(){
    vector<vector<char>> grid = {{'X', 'X', '1', '2', 'S'},
                                  {'3', '1', '1', '2', '1'},
                                  {'X', 'X', 'X', '2', 'D'}};

    unordered_map<char, int> costs = {{'1', 1}, {'2', 2}, {'3', 3}};  // Example costs per mode
    unordered_map<char, int> times = {{'1', 3}, {'2', 2}, {'3', 5}};  // Time per square for each mode

    // Define start point (last element in the first row is 'S')
    pair<int, int> start = {0, 4};

    // Call BFS to find the shortest time path
    auto [mode, cost, time] = bfs(grid, start, costs, times);

    if (cost != -1 && time != -1) {
        cout << "Mode: " << mode << ", Cost: " << cost << ", Time: " << time << endl;
    } else {
        cout << "No path found!" << endl;
    }
}
