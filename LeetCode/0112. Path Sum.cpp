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
    private:
        bool dfs(TreeNode* cur, int sum, int target){
            if(!cur->left && !cur->right)
                return sum+cur->val==target;
            if(cur->left && dfs(cur->left, sum+cur->val, target))
                return true;
            if(cur->right)
                return dfs(cur->right, sum+cur->val, target);
            return false;
        }
    public:
        bool hasPathSum(TreeNode* root, int targetSum) {
            if(!root) return false;
            return dfs(root, 0, targetSum);
        }
    };