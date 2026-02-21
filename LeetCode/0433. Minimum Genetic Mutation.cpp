class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        char dic[4] = {'A', 'C', 'G', 'T'};
        unordered_set<string> bankSet(bank.begin(), bank.end());
        unordered_set<string> visited;
        queue<string> q;
        q.push(startGene);
        visited.insert(startGene);
        int step = 0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                string curr = q.front();
                q.pop();
                if(curr == endGene) return step;
                for(int i = 0; i < 8; i++){
                    char old = curr[i];
                    for(int j = 0; j < 4; j++){
                        curr[i] = dic[j];
                        if (bankSet.count(curr) && !visited.count(curr)) {
                            visited.insert(curr);
                            q.push(curr);
                        }
                    }
                    curr[i] = old;
                }
            }
            step++;
        }
        return -1;
    }
};