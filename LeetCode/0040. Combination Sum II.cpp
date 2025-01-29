class Solution {
private:
    vector<vector<int>> ans;
    vector<int> tmp;
    vector<bool> used;
    void backtracking(vector<int>& candidates, int target, int idx, int sum){
        if(sum==target){
            ans.emplace_back(tmp);
            return;
        }
        for(int i = idx; i < candidates.size(); i++){
            if(sum+candidates[i]>target) break;
            if(i!=0 && candidates[i]==candidates[i-1] && !used[i-1]) continue;
            tmp.emplace_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target, i+1, sum+candidates[i]);
            tmp.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        used.resize(candidates.size());
        backtracking(candidates, target, 0, 0);
        return ans;
    }
};