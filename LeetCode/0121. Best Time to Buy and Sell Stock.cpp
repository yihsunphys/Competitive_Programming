class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int ans = 0;
            int tmp = 0;
            for(int i = 0; i < prices.size()-1; i++){
                tmp = max(0, tmp += prices[i+1]-prices[i]);
                ans = max(ans, tmp);
            }
            return ans;
        }
    };