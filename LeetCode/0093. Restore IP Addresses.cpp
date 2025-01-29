class Solution {
private:
    vector<string> ans;
    vector<string> tmp;
    bool isValid(const string& s, int start, int end){
        string sub = s.substr(start, end-start+1);
        if(end-start+1 > 3) return false;
        if(end!=start && s[start]=='0') return false;
        if(stoi(sub)<=255) return true;
        return false;
    }
    void backtracking(const string& s, int idx){
        if(idx == s.size() && tmp.size()==4){
            string ip = "";
            for(auto it = tmp.begin(); it!=tmp.end() ; it++){
                ip+=*it;
                if(it!=tmp.end()-1) ip+='.';
            }
            ans.emplace_back(ip);
            return;
        }
        if(tmp.size()>4) return;
        for(int i = idx; i < s.size(); i++){
            if(isValid(s, idx, i)){
                tmp.emplace_back(s.substr(idx, i-idx+1));
                backtracking(s, i+1);
                tmp.pop_back();
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size()<4 || s.size()>12) return ans;
        backtracking(s, 0);
        return ans;
    }
};