// 有可以用更少空間的方法
// 直接用ans儲存prefix 然後再從後面跑回來乘上suffix 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+1);
        vector<int> suffix(n+1);
        prefix[0] = 1, suffix[0] = 1;
        for(int i = 1; i <= n; i++){
            prefix[i] = prefix[i-1]*nums[i-1];
            suffix[i] = suffix[i-1]*nums[n-i]; 
        }
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = prefix[i]*suffix[n-i-1];
        }
        return ans;
    }
};