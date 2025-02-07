class Solution {
public:
    string reverseStr(string s, int k) {
        int idx = 0;
        while(idx+k<s.size()){
            int l = idx, r = idx+k-1;
            while(l<r){
                swap(s[l], s[r]);
                l++, r--;
            }
            idx+=2*k;
        }
        int l = idx, r = s.size()-1;
        while(l<r){
            swap(s[l], s[r]);
            l++, r--;
        }
        return s;
    }
};