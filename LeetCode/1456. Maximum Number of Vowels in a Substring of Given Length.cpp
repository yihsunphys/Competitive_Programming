class Solution {
public:
    bool isvowel(char ch) {
        return ch=='a' || ch=='e' || ch=='i' || ch=='o'|| ch=='u';
    } 
    int maxVowels(string s, int k) {
        int tmp = 0;
        for(int i = 0; i < k ; i++)
            if(isvowel(s[i])) tmp++;
        int ans = tmp;
        for(int i = k; i < s.size(); i++){
            if(isvowel(s[i-k])) tmp--;
            if(isvowel(s[i])) tmp++;
            ans = max(ans, tmp);
        }
        return ans;
    }
};