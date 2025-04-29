class Solution {
    public:
        class cmp {
        public:
            bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
                return lhs.second > rhs.second;
            }
        };
        vector<int> topKFrequent(vector<int>& nums, int k) {
            map<int, int> mp;
            for(auto it: nums){
                mp[it]++;
            }
            priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
            for(auto it: mp){
                pq.push(it);
                if(pq.size()>k)
                    pq.pop();
            }
            vector<int> ans;
            while(pq.size()){
                ans.push_back(pq.top().first);
                pq.pop();
            }
            return ans;
        }
    };