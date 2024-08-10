#include <vector>
#include <queue>
#include <map>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int, vector<int>> graph;

    void makeGraph(TreeNode* cur){
        if (cur->left) {
            graph[cur->val].push_back(cur->left->val);
            graph[cur->left->val].push_back(cur->val);
            makeGraph(cur->left);
        }
        if (cur->right) {
            graph[cur->val].push_back(cur->right->val);
            graph[cur->right->val].push_back(cur->val);
            makeGraph(cur->right);
        }
    }

    int findClosestLeaf(TreeNode* root, int k) {
        makeGraph(root);

        queue<int> q;
        map<int, bool> visited;
        q.push(k);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            visited[cur] = true;
            if (graph[cur].size() == 1 && cur != root->val || graph[cur].size() == 0) return cur;
            for (int n : graph[cur]){
                if (!visited[n])
                q.push(n);
            }
        }

        return 0;
    }
};
