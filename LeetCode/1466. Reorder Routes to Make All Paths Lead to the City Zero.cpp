class Solution {
public:
    int ans = 0;
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> visited(n, false);
        vector<vector<pair<int, bool>>> graph(n);
        for(auto edge: connections){
            graph[edge[0]].emplace_back(edge[1], true);
            graph[edge[1]].emplace_back(edge[0], false);
        }
        dfs(0, n, visited, graph);
        return ans;
    }
    void dfs(int idx, int n, vector<bool>& visited, vector<vector<pair<int, bool>>>& graph){
        visited[idx] = true;
        for(auto&[next, forward]:graph[idx]){
            if(visited[next]) continue;
            if(forward) ans++;
            dfs(next, n, visited, graph);
        }
        
    }
};