// 簡單的DFS
class Solution {
public:
    int n;
    int can_visit = 0;
    void dfs(int idx, vector<vector<int>>& rooms, vector<bool>& visited){
        visited[idx]=1;
        can_visit++;
        for(auto it: rooms[idx]){
            if(visited[it]==0){
                dfs(it, rooms, visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        n = rooms.size();
        vector<bool> visited(n);
        dfs(0, rooms, visited);
        cout << can_visit;
        if(can_visit == n) return 1;
        else return 0;
    }
};