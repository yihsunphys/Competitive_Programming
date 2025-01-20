// 簡單的字串操作題
class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 0;
        char cur = chars[0];
        vector<char> ans;
        for(auto i = 0; i != chars.size(); i++){
            if(chars[i] == cur) count++;
            else  cur = chars[i]; count = 1;
            if(i==chars.size()-1 || chars[i+1]!=cur){
                if(count == 1) ans.emplace_back(cur);
                else if(count!=0){
                    ans.emplace_back(cur);
                    string s = to_string(count);
                    for(auto j: s)
                        ans.emplace_back(j);
                }
            }
        }
        chars = ans;
        return ans.size();
    }
};