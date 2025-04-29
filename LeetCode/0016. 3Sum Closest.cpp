class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());
            int n = nums.size();
            int closest = nums[0] + nums[1] + nums[2]; // 初始值
    
            for (int i = 0; i < n - 2; ++i) {
                int left = i + 1;
                int right = n - 1;
    
                while (left < right) {
                    int sum = nums[i] + nums[left] + nums[right];
    
                    // 更新最接近答案
                    if (abs(sum - target) < abs(closest - target)) {
                        closest = sum;
                    }
    
                    if (sum == target) {
                        return sum; // 最佳答案，直接回傳
                    } else if (sum < target) {
                        left++; // 想辦法讓總和變大
                    } else {
                        right--; // 想辦法讓總和變小
                    }
                }
            }
    
            return closest;
        }
    };
    