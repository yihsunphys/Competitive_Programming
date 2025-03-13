class Solution {
    public:
        int findLengthOfLCIS(vector<int>& nums) {
            vector<int> dp(nums.size(), 1);
            for(int i = 0; i < nums.size()-1; i++){
                if(nums[i+1]>nums[i]) dp[i+1] = max(dp[i+1], dp[i]+1);
            }
            return *max_element(dp.begin(), dp.end());
        }
    };