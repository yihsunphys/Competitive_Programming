class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            unordered_map<char, int> umap;
            for(char ch: magazine){
                umap[ch]++;
            }
            for(auto ch: ransomNote){
                if(!umap.count(ch) || !umap[ch]) return false;
                else umap[ch]--;
            }
            return true;
        }
    };