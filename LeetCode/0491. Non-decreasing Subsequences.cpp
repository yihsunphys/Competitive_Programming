class Solution {
    private:
        vector<vector<int>> ans;
        vector<int> path;
        void backtracking(vector<int>& nums, int idx){
            if(path.size()>=2) ans.emplace_back(path);
            if(idx == nums.size()) return;
            unordered_set<int> uset;
            for(int i = idx; i < nums.size(); i++){
                if(!path.empty() && nums[i] < path.back() || uset.count(nums[i])) continue;
                path.emplace_back(nums[i]);
                uset.insert(nums[i]);
                backtracking(nums, i+1);
                path.pop_back();
            }
        }
    public:
        vector<vector<int>> findSubsequences(vector<int>& nums) {
            backtracking(nums, 0);
            return ans;
        }
    };