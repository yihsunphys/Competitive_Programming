// 想不到...
// two pointer: track smallest and mid
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int l = INT_MAX, m = INT_MAX;
        for(auto i: nums){
            if(i<=l) l = i;
            else if(i<=m) m = i;
            else return true;
        }
        return false;
    }
};