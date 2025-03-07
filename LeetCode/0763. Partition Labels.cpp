class Solution {
    public:
        vector<int> partitionLabels(string s) {
            map<int, int> mp;
            for(int i = 0; i < s.size(); i++){
                mp[s[i]] = i;
            }
            vector<int > ans;
            int tmp = 0;
            int sum = 0;
            for(int i = 0; i < s.size(); i++){
                if(i > tmp){
                    ans.push_back(tmp-sum+1);
                    sum = tmp+1;
                }
                tmp = max(tmp, mp[s[i]]);
            }
            ans.push_back(tmp-sum+1);
            return ans;
        }
    };