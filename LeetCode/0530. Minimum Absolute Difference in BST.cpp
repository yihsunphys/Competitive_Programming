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
        TreeNode* prev = nullptr;
        int mi = INT_MAX;
    
        void inorder(TreeNode* root) {
            if (!root) return;
            inorder(root->left);
            if (prev) {
                mi = min(mi, abs(root->val - prev->val));
            }
            prev = root;
            inorder(root->right);
        }
        int getMinimumDifference(TreeNode* root) {
            inorder(root);
            return mi;
        }
    };