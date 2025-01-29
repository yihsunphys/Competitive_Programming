class Solution {
private:
    vector<vector<int>> ans;
    vector<int> tmp;
    void backtracking(vector<int>& candidates, int target, int idx, int sum){
        if(sum==target){
            ans.emplace_back(tmp);
            return;
        }
        for(int i = idx; i < candidates.size(); i++){
            if(sum+candidates[i]>target) break;
            tmp.emplace_back(candidates[i]);
            backtracking(candidates, target, i, sum+candidates[i]);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return ans;
    }
};