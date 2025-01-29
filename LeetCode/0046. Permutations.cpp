class Solution {
private:
    vector<vector<int>> ans;
    vector<int> tmp;
    vector<bool> used;
    void backtracking(vector<int>& nums){
        if(tmp.size() == nums.size()){
            ans.emplace_back(tmp);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i]) continue;
            tmp.emplace_back(nums[i]);
            used[i] = true;
            backtracking(nums);
            tmp.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size());
        backtracking(nums);
        return ans;
    }
};