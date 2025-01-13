class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double tmp = 0;
        for(int i = 0; i < k; i++){
            tmp+=nums[i];
        }
        double ans = tmp/k;
        for(int i = k; i < nums.size(); i++){
            tmp-=nums[i-k];
            tmp+=nums[i];
            ans = max(ans, tmp/k);
        }
        return ans;
    }
};