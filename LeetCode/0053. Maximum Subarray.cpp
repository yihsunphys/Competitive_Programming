class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int ans = INT_MIN, tmp = 0;
            for(auto e: nums){
                tmp += e;
                ans = max(ans, tmp);
                if(tmp < 0) tmp = 0;
            }
            return ans;
        }
    };