class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int items = nums.size();
        vector<uint64_t> dp(target+1, 0);
        dp[0]= 1;
        for(int i = 0; i <= target; i++){
            for(int j = 0; j < items; j++){
                if(i>=nums[j])
                    dp[i] += dp[i-nums[j]];
            }
        }
        return dp[target];
    }
};