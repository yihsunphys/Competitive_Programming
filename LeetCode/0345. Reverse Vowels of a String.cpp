class Solution {
public:
    bool isvowel(char ch){

        return ( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }
    string reverseVowels(string s) {
        int l = 0, r = s.size()-1;
        while(l<r){
            if(isvowel(s[l]) && isvowel(s[r])){
                swap(s[l], s[r]);
                l++, r--;
            }
            else{
                if(!isvowel(s[l])) l++;
                if(!isvowel(s[r])) r--;
            }
        }
        return s;
    }
};