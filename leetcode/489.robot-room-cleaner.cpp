/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    const vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // up right down left FUCK dir is relative

    void revert(Robot& robot){
        robot.turnRight();
        robot.turnRight(); // 180 deg
        robot.move(); // go back
        robot.turnRight();
        robot.turnRight(); // revert ori

    }
    void dfs(Robot& robot, unordered_map<string, int> &visited, int curr, int curc, int d){
        robot.clean();
        visited[to_string(curr) + "idk" + to_string(curc)] = 1;
        for (int i = 0; i < 4; ++i){
            int nr = curr + dirs[(d + i) % 4].first, nc = curc + dirs[(d + i) % 4].second;
            if ((visited[to_string(nr) + "idk" + to_string(nc)] != 1) && robot.move()){
                dfs(robot, visited, nr, nc, (d + i)%4);
                revert(robot);
            }
            robot.turnRight(); // face next dir to match next nr nc
        }
    }
    void cleanRoom(Robot& robot) {
        unordered_map<string, int> visited;
        dfs(robot, visited, 0, 0, 0); //
    }
};
