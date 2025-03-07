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
// 0: 無覆蓋 1: 有camera 2: 被覆蓋
class Solution {
    private:
        int ans = 0;
        int dfs(TreeNode* root){
            if(root == nullptr) return 2;
            int left = dfs(root->left);
            int right = dfs(root->right);
            if(left == 0 || right == 0){
                ans++;
                return 1;
            }
            if(left == 1 || right == 1){
                return 2;
            }
            if(left == 2 && right == 2){
                return 0;
            }
            return -1;
        }
    public:
        int minCameraCover(TreeNode* root) {
            if(dfs(root) == 0) ans++;
            return ans;
        }
    };