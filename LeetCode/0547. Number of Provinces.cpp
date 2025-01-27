class Solution {
public:
    int n;
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        n = isConnected.size();
        vector<bool> visited(n);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, visited, isConnected); ans++;
            }
        }
        return ans;
    }
    void dfs(int idx, vector<bool>& visited, vector<vector<int>>& isConnected){
        visited[idx] = 1;
        for(int i = 0; i < n; i++){
            if(visited[i]) continue;
            if(isConnected[idx][i]) dfs(i, visited, isConnected);
        }
    }
};