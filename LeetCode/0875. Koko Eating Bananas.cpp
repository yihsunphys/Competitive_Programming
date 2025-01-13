// 簡單的BS
// 注意ceil函數裡面要是double 或用(it+k-1)/k
// 注意count > h 時就可以return 避免溢位
class Solution {
public:
    bool isok(vector<int>& piles, int k, int h){
        int count = 0;
        for(auto it: piles) {
            count += (it+k-1)/k;
            if(count > h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while(l<=r){
            int m = l+(r-l)/2;
            if(isok(piles, m, h)) {r = m-1;}
            else l = m+1;
        }
        return l;
    }
};