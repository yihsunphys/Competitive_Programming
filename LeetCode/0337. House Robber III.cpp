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
        int rob(TreeNode* root) {
            vector<int> ans = dp(root);
            return max(ans[0], ans[1]);
        }
        vector<int> dp(TreeNode* cur){
            if (cur == NULL) return vector<int>{0, 0};
            vector<int> left = dp(cur->left);
            vector<int> right = dp(cur->right);
            int val1 = cur->val + left[0] + right[0];
            int val2 = max(left[0], left[1]) + max(right[0], right[1]);
            return {val2, val1}; 
        }
    };