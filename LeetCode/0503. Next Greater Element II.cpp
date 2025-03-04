class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) {
            stack<int> stk;
            vector<int> nums1(nums.begin(), nums.end());
            nums.insert(nums.end(), nums1.begin(), nums1.end());
            vector<int> ans(nums.size(), -1);
            stk.push(0);
            for(int i = 1; i < nums.size(); i++){
                while(!stk.empty() && nums[stk.top()] < nums[i]){
                    ans[stk.top()] = nums[i]; 
                    stk.pop();
                }
                stk.push(i);
            }
            ans.resize(nums.size() / 2);
            return ans;
        }
    };