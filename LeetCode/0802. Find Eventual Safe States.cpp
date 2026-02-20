class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int idx, vector<int>& state){
        if(state[idx]>0){
            return state[idx]==2;
        }
        state[idx] = 1;
        for(auto it: graph[idx]){
            if(!dfs(graph, it, state)) return false;
        }
        state[idx] = 2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0);
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(dfs(graph, i, state)) 
                ans.emplace_back(i);
        }
        return ans;
    }
};