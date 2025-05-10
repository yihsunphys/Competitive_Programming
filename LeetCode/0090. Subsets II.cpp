class Solution {
    public:
        vector<vector<int>> ans;
        vector<int> tmp;
        void backtracking(vector<int>& nums, int idx){
            ans.emplace_back(tmp);
            for(int i = idx; i < nums.size(); i++){
                if(i>idx && nums[i]==nums[i-1]) continue;
                tmp.push_back(nums[i]);
                backtracking(nums, i+1);
                tmp.pop_back();
            }
        }
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            backtracking(nums, 0);
            return ans;
        }
    };