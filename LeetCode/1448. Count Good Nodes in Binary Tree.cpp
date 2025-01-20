//用vector紀錄路徑 再看max_element
//更快 紀錄最大值就好
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
    void dfs(TreeNode* root, int mx){
        if(!root) return;
        if(mx <= root->val){
            mx = root->val;
            ans++;
        }
        dfs(root->left, mx);
        dfs(root->right, mx);
    }
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return ans;
    }
};