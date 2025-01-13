//*
// 最佳解: quick select, 找最大最小第k大都是average O(n), 但是最差可能O(n^2) 
// 用雙指針能避免重複元素時的最差情況
// count sort: O(n+k)
// heap: O(nlgn), 用priority queue
// sort: O(nlgn)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int targetIdx = nums.size() - k;
        return quickSelect(nums, 0, nums.size() - 1, targetIdx);
    }
    
    int quickSelect(vector<int>& nums, int left, int right, int targetIdx) {
        if (left == right) {
            return nums[left];
        }

        int pivot = nums[left];
        int low = left;
        int high = right;

        while (low <= high) {
            while (low <= high && nums[low] < pivot) {
                low++;
            }
            while (low <= high && nums[high] > pivot) {
                high--;
            }
            if (low <= high) {
                swap(nums[low], nums[high]);
                low++;
                high--;
            }
        }

        if (targetIdx <= high) {
            return quickSelect(nums, left, high, targetIdx);
        } else if (targetIdx >= low) {
            return quickSelect(nums, low, right, targetIdx);
        } else {
            return nums[targetIdx];
        }
    }
};