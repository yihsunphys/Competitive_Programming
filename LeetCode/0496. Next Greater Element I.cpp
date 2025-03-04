class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int, int> mp;
            stack<int> stk;
            stk.push(0);
            for(int num: nums2){
                while(!stk.empty() && stk.top() < num){
                    mp[stk.top()] = num;
                    stk.pop();
                }
                stk.push(num);
            }
            vector<int> ans;
            for(int num: nums1){
                ans.push_back(mp.count(num) ? mp[num] : -1);
            }
            return ans;
        }
    };