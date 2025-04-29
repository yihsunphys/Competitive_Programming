class Solution {
    public:
        TreeNode* pre = nullptr;
        int tmp = 1, mx = 0;
        vector<int> res;
    
        void inorder(TreeNode* root) {
            if (!root) return;
            inorder(root->left);
            if (pre && pre->val == root->val)  tmp++;
            else  tmp = 1;
            if (tmp > mx) {
                res.clear();       // 新的最大頻率，清空原有的結果
                res.push_back(root->val);
                mx = tmp;
            } 
            else if (tmp == mx) {
                res.push_back(root->val);
            }
            pre = root;
            inorder(root->right);
        }
    
        vector<int> findMode(TreeNode* root) {
            inorder(root);
            return res;
        }
    };
    