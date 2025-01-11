//沒有難度的字串操作
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        int pointer = 0;
        string ans = "";
        while(pointer<n&&pointer<m){
          ans+=word1[pointer];
          ans+=word2[pointer];
          pointer++;
        }
        while(pointer<n){
          ans+=word1[pointer];
          pointer++;
        }
        while(pointer<m){
          ans+=word2[pointer];
          pointer++;
        }
        return ans;
    }
};