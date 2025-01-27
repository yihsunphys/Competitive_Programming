class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;    
        dfs(1, 0, k, n, v);
        return ans;
    }
    void dfs(int num, int sum, int k, int n, vector<int>& v){
        if(v.size()==k){
            if(sum==n) ans.emplace_back(v);
            else return;
        }
        for(int i = num; i <= 9; i++){
            if(sum+i>n) break;
            else {
                v.emplace_back(i);
                dfs(i+1, sum+i, k, n, v);
                v.pop_back();
            }
        }
    }
};