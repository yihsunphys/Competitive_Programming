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
    int dfs(TreeNode* root){
        int l = 0, r = 0;
        if(root==nullptr) return 0;
        l = dfs(root->left);
        r = dfs(root->right);
        return max(l, r)+1;
    }
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
};