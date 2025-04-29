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
        TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
            if(nums.size()==0) return nullptr;
            int val = *(max_element(nums.begin(), nums.end()));
            TreeNode* root = new TreeNode(val);
            if(nums.size()==1) return root;
            // 切割
            int i;
            for(i = 0; i < nums.size(); i++){
                if(nums[i]==val) break; 
            }
            vector<int> Left(nums.begin(), nums.begin()+i); //左閉右開
            vector<int> Right(nums.begin()+i+1, nums.end());
            root->left = constructMaximumBinaryTree(Left);
            root->right = constructMaximumBinaryTree(Right);
            return root;
        }
    };