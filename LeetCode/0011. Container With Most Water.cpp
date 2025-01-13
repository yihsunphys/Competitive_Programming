// 對每個元素跑一次 左右各一個指針者第一個比自己大的? O(n^2) 太慢
// 雙指針: 左右各一個 只移動短邊 O(n) 因為只有移動短邊才可能更大
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int ans = 0;
        while(l<r){
            int idx = height[l]>height[r]? r:l;
            ans = max(ans, (r-l)*height[idx]);
            if(idx==l) l++;
            else r--;
        }
        return ans;
    }
};