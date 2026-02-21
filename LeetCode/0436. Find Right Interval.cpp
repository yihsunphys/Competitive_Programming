class Solution {
public:
    int bs(const vector<pair<int, int>>& vec, int target){
        int l = 0, r = vec.size()-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(vec[m].first>=target) {
                r = m-1;
            }
            else  l = m+1;
        }
        if (l == vec.size()) return -1;
        return vec[l].second;
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> starts;
        for (int i = 0; i < n; ++i) {
            starts.push_back({intervals[i][0], i});
        }
        sort(starts.begin(), starts.end());
        vector<int> ans;
        for(int i = 0 ; i < intervals.size(); i++){
            ans.push_back(bs(starts, intervals[i][1]));
        }
        return ans;
    }
};