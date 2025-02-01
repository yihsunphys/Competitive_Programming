class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int k = nums.size()-1;
        vector<int> ans(nums.size());
        for(int i = 0, j = nums.size()-1; i<=j;){
            if(nums[j]*nums[j] > nums[i]*nums[i]){ 
                ans[k--] = nums[j]*nums[j]; j--;
            }
            else {
                ans[k--] = nums[i]*nums[i]; i++;
            }
        }
        return ans;
    }
};