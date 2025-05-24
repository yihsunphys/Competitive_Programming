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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){  
            return root;
        }
        if(root->val == key){
            if(!root->left && !root->right){
                delete root;
                return nullptr;
            } 
            else if(!root->left){
                auto newroot = root->right;
                delete root;
                return newroot;
            }
            else if(!root->right){
                auto newroot = root->left;
                delete root;
                return newroot;
            }
            else{
                auto cur = root->right;
                while(cur->left){
                    cur = cur->left;
                }
                cur->left = root->left;
                auto newroot = root->right;
                delete root;
                return newroot;
            }
        }
        if(root->val > key) root->left = deleteNode(root->left, key);
        if(root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};