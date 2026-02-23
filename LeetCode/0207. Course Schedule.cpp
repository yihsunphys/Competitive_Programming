class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(auto it: prerequisites){
            indegree[it[0]]++;
            adj[it[1]].push_back(it[0]);
        } 
        int num = 0;
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i]==0) q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            count++;
            for(auto it : adj[curr]){
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        if(count!=numCourses) return false;
        else return true; 
    }
};