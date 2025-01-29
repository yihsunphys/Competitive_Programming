class Solution {
private:
    vector<string> ans;
    string tmp = "";
    const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };
    void backtracking(string& digits, int idx){
        if(idx == digits.size()){
            ans.push_back(tmp);
            return;
        } 
        for(auto it: letterMap[digits[idx]-'0']){
            tmp+=it;
            backtracking(digits, idx+1);
            tmp.pop_back();
        }
    } 
public:
    vector<string> letterCombinations(string digits) {
        if(digits == "") return ans;
        backtracking(digits, 0);
        return ans;
    }
};