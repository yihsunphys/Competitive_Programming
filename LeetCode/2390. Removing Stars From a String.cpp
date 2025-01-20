// easy
class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        for(auto i: s){
            if(i=='*')  ans.pop_back();
            else ans+=i;
        }
        return ans;
    }
};