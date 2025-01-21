// 想辦法分成重量相同的兩堆 01背包變化題
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(auto i: stones) sum+=i;
        int capacity  = sum/2;
        vector<int> dp(capacity+1, 0);
        for(int i = 0; i < stones.size(); i++){
            for(int j = capacity; j >= stones[i]; j--){
                dp[j] = max(dp[j], dp[j-stones[i]]+stones[i]);
            }
        }
        return sum-2*dp[capacity];
    }
};