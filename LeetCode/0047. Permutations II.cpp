class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
    void backtracking(vector<int>& nums, vector<bool>& used){
        if(path.size() == nums.size()){
            ans.emplace_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i]) continue;
            if(i!=0 && nums[i]==nums[i-1] && !used[i-1]) continue;
            path.emplace_back(nums[i]);
            used[i] = true;
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, used);
        return ans;
    }
};