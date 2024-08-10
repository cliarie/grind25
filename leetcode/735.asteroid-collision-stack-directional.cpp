#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> ast;
        int n = asteroids.size();
        for (auto &a : asteroids){
            if (!ast.empty() && a < 0 && ast.top() > 0){
                int greater = a;
                while(!ast.empty() && greater < 0 && ast.top() > 0 && greater != -ast.top()){
                    if (abs(greater) < abs(ast.top())) greater = ast.top();
                    ast.pop();
                }
                if (!ast.empty() && greater < 0 && ast.top() > 0 && greater == -ast.top()) ast.pop();
                else ast.push(greater);
            }
            else ast.push(a);
        }
        vector<int> ans;
        while(!ast.empty()){
            ans.push_back(ast.top());
            ast.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
