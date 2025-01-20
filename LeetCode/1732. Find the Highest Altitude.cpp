class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, mx = 0;
        for(auto i: gain){
            ans += i;
            mx = max(mx, ans);
        }
        return mx;
    }
};