class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0;
        map<vector<int>, int> mp;
        for(auto i: grid) {
            mp[i]++;
        }
        vector<vector<int>> v(grid.size());
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid.size(); j++){
                v[j].push_back(grid[i][j]);
            }
        }
        for(auto i: v) {
            ans+=mp[i];
        }
        return ans;
    }
};