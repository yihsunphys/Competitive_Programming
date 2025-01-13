// 三指針 l, r, 第一個零(pq)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int ans = 0;
        int f = 0;
        while(r<nums.size()){
            if(nums[r]==0) {f++;}
            if(f>k){
                if(nums[l]==0) f--;
                l++;
            }
            r++;
        }
        return r-l;
    }
};