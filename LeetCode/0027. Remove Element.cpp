// l之前都是非val r之後都是val
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            if (nums[l] == val && nums[r] != val) {
                swap(nums[l], nums[r]);
            }
            if (nums[l] != val) {
                l++;
            }
            if (nums[r] == val) {
                r--;
            }
        }
        return l;
    }
};
