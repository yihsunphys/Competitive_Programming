//*
//binary search
//因為左右邊界都是負無限大，一定有解
//如果num[mid]<num[mid+1], 則右半邊可以看做跟原本的問題一樣
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0,  r = nums.size() - 1;
        while (l < r) {
            int m = l+(r-l) / 2;
            if (nums[m] > nums[m+1]) r = m;
            else l = m + 1;
        }
        return l;        
    }
};