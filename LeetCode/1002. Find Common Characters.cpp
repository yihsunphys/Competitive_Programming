class Solution {
    public:
        vector<string> commonChars(vector<string>& words) {
            int n = words.size();
            int a[n][26]; 
            memset(a, 0, sizeof(a));
            for(int i = 0; i < n; i++) {
                for(char c : words[i]) {
                    a[i][c - 'a']++;
                }
            }
    
    
            int ans[26];
            memset(ans, 0, sizeof(ans));
            for(int i = 0; i < 26; i++) {
                ans[i] = a[0][i]; 
                for(int j = 1; j < n; j++) {
                    ans[i] = min(ans[i], a[j][i]);
                }
            }
    
    
            vector<string> v;
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < ans[i]; j++) {
                    v.emplace_back(string(1, 'a' + i)); 
                }
            }
            return v;
        }
    };
    