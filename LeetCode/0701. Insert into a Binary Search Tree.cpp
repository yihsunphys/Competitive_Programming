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
        TreeNode* insertIntoBST(TreeNode* root, int val) {
            if(!root) return new TreeNode(val);
            if(val < root->val){
                if(!root->left) root->left = new TreeNode(val);
                else insertIntoBST(root->left, val);
            }
            else if(val > root->val){
                if(!root->right) root->right = new TreeNode(val);
                else insertIntoBST(root->right, val);
            }
            return root;
        }
    };