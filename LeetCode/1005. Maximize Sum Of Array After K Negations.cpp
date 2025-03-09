class Solution {
    public:
        int largestSumAfterKNegations(vector<int>& nums, int k) {
            sort(nums.begin(), nums.end());
            int sum = 0;
            for(int i = 0; i < nums.size() && k; i++){
                if(nums[i] < 0) {
                    nums[i] = -nums[i]; k--;
                }
                else break;
            }
            sort(nums.begin(), nums.end());
            if(k%2) nums[0] = -nums[0];
            for(int i = 0; i < nums.size(); i++)
                sum+=nums[i];
            return sum;
        }
    };