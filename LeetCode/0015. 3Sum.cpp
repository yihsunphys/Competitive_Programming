class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<vector<int>> ans;
            for(int k = 0; k < nums.size()-2; k++){
                if(k!=0 && nums[k]==nums[k-1]) continue;
                int target = -nums[k];
                int l = k+1, r = nums.size()-1;
                while(l<r){
                    if(nums[l]+nums[r] == target){
                        ans.push_back({nums[k], nums[l], nums[r]});
                        while(r>l && nums[l+1] == nums[l]) l++;
                        while(r>l && nums[r-1] == nums[r]) r--;
                        l++, r--;
                    }
                    else if(nums[l]+nums[r] > target) r--;
                    else l++;
                }
            }
            return ans;
        }
    };