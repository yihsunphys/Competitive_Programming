class Solution {
    public:
        static bool cmp(const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        }
        vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
            sort (people.begin(), people.end(), cmp);
            vector<vector<int>> ans;
            for (auto i: people) {
                ans.insert(ans.begin() + i[1], i);
            }
            return ans;
        }
    };