class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());
            vector<vector<int>> ans;
            if (nums.size() < 4) return {};
            for(int q = 0; q < nums.size()-3; q++){
                if(q!=0 && nums[q]==nums[q-1]) continue;
                for(int k = q+1; k < nums.size()-2; k++){ 
                    if(k!=q+1 && nums[k]==nums[k-1]) continue;
                    long long x = (long long)target - nums[k] - nums[q];
                    int l = k+1, r = nums.size()-1;
                    while(l<r){
                        if(nums[l]+nums[r] == x){
                            ans.push_back({nums[q], nums[k], nums[l], nums[r]});
                            while(r>l && nums[l+1] == nums[l]) l++;
                            while(r>l && nums[r-1] == nums[r]) r--;
                            l++, r--;
                        }
                        else if(nums[l]+nums[r] > x) r--;
                        else l++;
                    }
                }
            }
            return ans;
        }
    };