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
        int ans = 0, mx_depth = -1;
        void dfs(TreeNode* cur, int depth){
            if(!cur) return;
            if(!cur->left && !cur->right && depth>=mx_depth){
                ans = cur->val;
                mx_depth = depth;
            }
            dfs(cur->right, depth+1);
            dfs(cur->left, depth+1);
        }
    public:
        int findBottomLeftValue(TreeNode* root) {
            dfs(root, 0);
            return ans;
        }
    };