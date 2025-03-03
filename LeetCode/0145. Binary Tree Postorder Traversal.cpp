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
        void postorder(TreeNode* root, vector<int>& ans) {
            if (root) {
                postorder(root->left, ans);  // 左子樹
                postorder(root->right, ans);  // 右子樹
                ans.push_back(root->val);     // 根節點
            }
        }
    public:
        vector<int> ans;
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> ans;  // 讓 ans 成為局部變數
            postorder(root, ans);  // 傳遞給遞迴函數
            return ans;
        }
    };