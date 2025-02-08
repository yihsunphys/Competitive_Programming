class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            set<int> st1(nums1.begin(), nums1.end());
            set<int> st2;
            for(auto e: nums2){
                if(st1.count(e))
                    st2.insert(e);
            }
    
            return vector<int>(st2.begin(), st2.end());
        }
    };