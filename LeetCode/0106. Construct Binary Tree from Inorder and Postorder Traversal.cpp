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
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            if(postorder.size()==0) return nullptr;
            int val = postorder.back();
            TreeNode* root = new TreeNode(val);
            if(postorder.size()==1) return root;
            // 切割
            int i;
            for(i = 0; i < inorder.size(); i++){
                if(inorder[i]==val) break; 
            }
            vector<int> LeftInorder(inorder.begin(), inorder.begin()+i); //左閉右開
            vector<int> RightInorder(inorder.begin()+i+1, inorder.end()); 
            vector<int> LeftPostorder(postorder.begin(), postorder.begin()+LeftInorder.size()); 
            vector<int> RightPostorder(postorder.begin()+LeftInorder.size(), postorder.end()-1); 
            
    
            root->left = buildTree(LeftInorder, LeftPostorder);
            root->right = buildTree(RightInorder, RightPostorder);
            return root;
        }
    };