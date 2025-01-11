// 簡單 backtracking
class Solution {
public:
    vector<string> ans;
    vector<vector<char>> alp = vector<vector<char>>(10);
    void dfs(int idx, int n, string tmp, string digits){
        if(idx == n){
            ans.push_back(tmp);
            return;
        } 
        for(auto it: alp[digits[idx]-'0']){
            tmp+=it;
            dfs(idx+1, n, tmp, digits);
            tmp.pop_back();
        }
    } 
    vector<string> letterCombinations(string digits) {
        if(digits == "") return ans;
        int n = digits.size();
        alp[2] = {'a', 'b', 'c'}; alp[3] = {'d', 'e', 'f'}; alp[4] = {'g', 'h', 'i'};
        alp[5] = {'j', 'k', 'l'}; alp[6] = {'m', 'n', 'o'}; alp[7] = {'p', 'q', 'r', 's'};
        alp[8] = {'t', 'u', 'v'}; alp[9] = {'w', 'x', 'y', 'z'};
        dfs(0, n, "", digits);
        return ans;
    }
};