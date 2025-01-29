class Solution {
private:
    vector<vector<int>> ans;
    vector<int> tmp;
    void backtracking(int k, int n, int idx, int sum){
        if(tmp.size()==k){
            if(sum==n) ans.emplace_back(tmp);
            return;
        }
        for(int i = idx; i <= 9; i++){
            if(sum+i>n) break;
            else {
                tmp.emplace_back(i);
                backtracking(k, n, i+1, sum+i);
                tmp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {  
        backtracking(k, n, 1, 0);
        return ans;
    }
};