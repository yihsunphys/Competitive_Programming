class Solution {
public:
    bool isAnagram(string s, string t) {
        multiset<char> st;
        for(auto it: s)
            st.insert(it);
        for(auto it: t){
            if(!st.count(it)) return false;
            st.erase(st.find(it));
        }
        return st.empty();
    }
};