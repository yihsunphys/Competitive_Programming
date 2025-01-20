class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> pre(nums.size()+1);
        pre[0] = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            pre[i+1] = pre[i]+nums[i];
            sum += nums[i];
        }
        for(int i = 0; i < nums.size(); i++){
            if(pre[i] == sum-pre[i]-nums[i]) return i;
        }
        return -1;
    }
};