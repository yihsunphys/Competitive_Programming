// 簡單的binary search
class Solution {
public:
    int lower_bound(vector<int>& potions, int it, long long success){
        int l = 0, r = potions.size()-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if((long long)potions[m]*it >= success) r = m-1;
            else l = m+1;
        }
        return l;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        int n = potions.size();
        sort(potions.begin(), potions.end());
        for(auto it: spells){
            ans.push_back(n-lower_bound(potions, it, success));
        }    
        return ans;
    }
};