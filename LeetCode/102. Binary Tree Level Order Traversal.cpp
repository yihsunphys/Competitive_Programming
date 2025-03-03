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
        void levelorder(TreeNode* root, vector<vector<int>>& ans, int depth){
            if(!root) return;
            if(depth == ans.size()) ans.emplace_back(vector<int>());
            ans[depth].emplace_back(root->val);
            levelorder(root->left, ans, depth+1);
            levelorder(root->right, ans, depth+1);
        }
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> ans;
            levelorder(root, ans, 0);
            return ans;
        }
    };