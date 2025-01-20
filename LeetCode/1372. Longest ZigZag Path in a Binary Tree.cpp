class Solution {
public:
    int ans = 0;
    void dfs(TreeNode* root, int cur, int dir) {
        if (!root) return;
        ans = max(ans, cur);
        if (dir != 1 && root->right) dfs(root->right, cur + 1, 1);
        else if (root->right) dfs(root->right, 1, 1);
        if (dir != 2 && root->left) dfs(root->left, cur + 1, 2);
        else if (root->left) dfs(root->left, 1, 2);
    }

    int longestZigZag(TreeNode* root) {
        dfs(root, 0, 0); // 初始化方向為 0，不限制方向
        return ans;
    }
};
