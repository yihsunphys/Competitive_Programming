// 有點難 只想到考慮每個最小的num2  
// 排序nums2 in decreasing order 每次排除最小nums1(用pq) sum+=nums1[i] 最小nums2就是nums2[i]
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> v;
        int n = nums1.size();
        for(int i = 0; i < n; i++){
            v.push_back({nums2[i], nums1[i]});
        }
        sort(v.rbegin(), v.rend());
        long long sum = 0, ans = 0;
        priority_queue<int> pq; //紀錄最小nums1
        for(int i = 0; i < k-1; i++){
            sum+=v[i].second;
            pq.push(-v[i].second);
        }
        for(int i = k-1; i < n; i++){ //i是最小nums2
            sum+=v[i].second;
            pq.push(-v[i].second); //插入nums1[i]
            ans = max(ans, v[i].first*sum);
            sum+=pq.top();
            pq.pop(); //移除最小nums1
            
        }
        return ans;
    }
};