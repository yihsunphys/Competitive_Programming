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
        int strStr(string haystack, string needle) {
            vector<int> next = getnext(needle);
            int j = -1; 
            for(int i = 0; i < haystack.size(); i++){ 
                while(haystack[i] != needle[j+1] && j>=0){
                    j = next[j];
                }
                if(haystack[i] == needle[j+1]){
                    j++;
                }
                if(j == needle.size()-1){
                    return i-j;
                }
            }
            return -1;
        }
    };