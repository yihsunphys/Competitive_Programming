class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, r = 0;
        int ans = 0;
        int f = 0;
        while(r<nums.size()){
            if(nums[r]==0) {f++;}
            if(f>1){
                if(nums[l]==0) f--;
                l++;
            }
            r++;
        }
        return r-l-1;
    }
};