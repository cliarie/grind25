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
    int sum;
    int dfs(TreeNode *cur, int &sum){
        if (cur == nullptr) return 0;
        int lsum = max(dfs(cur->left, sum), 0); // could have negative values
        int rsum = max(0, dfs(cur->right, sum));
        cout << lsum << " " << rsum << endl;
        sum = max(sum, lsum + rsum + cur->val);
        return max(lsum + cur->val, rsum + cur->val);
    }
    int maxPathSum(TreeNode* root) {
        // max path always goes through some root, find path from root to 2 greatest children them sum
        sum = root->val;
        int t= dfs(root, sum);
        return sum;
    }
};
