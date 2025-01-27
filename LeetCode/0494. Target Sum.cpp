// 分組 a-b = target, a+b = sum, 求和為a的組合數 a>0
// dp[i][j] = 用0~i的item組合成j的方法數
// 最上列初始化 注意nums[0]可能=0
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int items = nums.size();
        for(auto i: nums) sum+=i;
        if((sum+target)%2  || target>sum || target+sum<0) return 0;
        int capacity  = (sum+target)/2;
        vector<int> dp(capacity+1, 0);
        dp[0]++;
        if(nums[0]<=capacity)  dp[nums[0]]++;
        // for(int i = 1; i < items; i++){
        //     for(int j = 0; j <= capacity; j++){
        //         if(nums[i]>j) dp[i][j] = dp[i-1][j];
        //         else dp[i][j] = dp[i-1][j]+dp[i-1][j-nums[i]];
        //     }
        // }
        for(int i = 1; i < items; i++){
            for(int j = capacity; j >= nums[i]; j--){
                dp[j] = dp[j]+dp[j-nums[i]];
            }
        }
        return dp[capacity];
    }
};