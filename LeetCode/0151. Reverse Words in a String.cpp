// stringstream
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> v;
        string word;
        while(ss >> word){
            v.emplace_back(word);
        }
        string ans="";
        for(auto it = v.rbegin(); it!=v.rend(); it++){
            ans+=*it;
            if(it!=v.rend()-1) ans+=" ";
        }
        return ans; 
    }
};