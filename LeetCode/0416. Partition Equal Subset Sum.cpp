// 01背包問題的問題
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i: nums) sum+=i;
        if(sum%2) return false;
        int capacity  = sum/2;
        vector<int> dp(capacity+1, 0);
        for(int i = 0; i < nums.size(); i++){
            for(int j = capacity; j >= nums[i]; j--){
                dp[j] = max(dp[j], dp[j-nums[i]]+nums[i]);
            }
        }
        if(dp[capacity]==capacity) return true;
        else return false;
    }
};