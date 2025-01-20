// char 組成相同 頻率組成相同 -> same
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char, int> mp1, mp2;
        set<char> set1, set2;
        for(int i = 0; i < word1.size(); i++){
            mp1[word1[i]]++;
            set1.insert(word1[i]);
        }
        for(int i = 0; i < word2.size(); i++){
            mp2[word2[i]]++;
            set2.insert(word2[i]);
        }
        if(set1!=set2) return false;
        multiset<int> st1, st2;
        for(auto i: mp1){
            st1.insert(i.second);
        }
        for(auto i: mp2){
            st2.insert(i.second);
        }
        if(st1 == st2) return true;
        return false;
    }
};