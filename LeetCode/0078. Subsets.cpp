class Solution {
private:
    vector<vector<int>> ans;
    vector<int> tmp;
    void backtracking(vector<int> nums, int idx){
        ans.emplace_back(tmp);
        for(int i = idx; i < nums.size(); i++){
            tmp.emplace_back(nums[i]);
            backtracking(nums, i+1);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return ans;
    }
};