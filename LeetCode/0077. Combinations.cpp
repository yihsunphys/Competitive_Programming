class Solution {
private:
    vector<vector<int>> ans;
    vector<int> tmp;
    void backtracking(int n, int k, int idx){
        if(tmp.size()==k){
            ans.emplace_back(tmp);
            return;
        }
        for(int i = idx; i <= n-(k-tmp.size())+1; i++){
            tmp.emplace_back(i);
            backtracking(n, k, i+1);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return ans;
    }
};