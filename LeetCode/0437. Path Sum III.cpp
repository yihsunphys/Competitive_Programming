//跑每個子樹時把cur=0也跑一次 
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
    int ans = 0; 
    void dfs(TreeNode* root, long long cur, int targetSum){
        if(!root) return; 
        if(cur+root->val == targetSum) ans++;
        dfs(root->left, cur+root->val, targetSum);
        dfs(root->right, cur+root->val, targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root){
            dfs(root, 0, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return ans;
    }
};