class Solution {
public:
    int gcd(int x, int y){
      if(x>y) swap(x, y);
      if(y%x==0) return x;
      return gcd(y%x, x);
    }
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2 != str2+str1) return "";
        int n = str1.size(), m = str2.size();
        return str1.substr(0,gcd(n,m));
    }
};