class Solution {
    private:
        vector<int> getnext(const string& str){
                int n = str.size();
                vector<int> next(n);
                next[0] = -1;
                int j = -1; //匹配到的前綴的末端index
                for(int i = 1; i < n; i++){ //後綴的末端index
                    while(str[i] != str[j+1] && j>=0){
                        j = next[j];
                    }
                    if(str[i] == str[j+1]){
                        j++;
                    }
                    next[i] = j;
                }
                return next;
            }
    public:
        bool repeatedSubstringPattern(string s) {
            vector<int> next = getnext(s);
            int len = s.size();
            if(len%(len-(next[len-1]+1))==0 && next[len-1]!=-1)
                return true;
            return false;
        }
    };