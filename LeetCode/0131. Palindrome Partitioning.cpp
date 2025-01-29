class Solution {
    vector<vector<string>> ans;
    vector<string> tmp;
    bool isPalindrome(const string& s){
        int i = 0, j = s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    void backtracking(const string& s, int idx){
        if(idx == s.size()){
            ans.emplace_back(tmp);
            return ;
        }
        for(int i = idx; i < s.size(); i++){
            if(isPalindrome(s.substr(idx, i-idx+1))){
                tmp.emplace_back(s.substr(idx, i-idx+1));
                backtracking(s, i+1);
                tmp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return ans;
    }
};