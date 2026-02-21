class Solution {
public:
    int bs(vector<char>& vec, char target){
        int l = 0, r = vec.size()-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(vec[m]>target) r=m-1;
            else if(vec[m]<=target) l=m+1;
        }
        return l;
    }
    char nextGreatestLetter(vector<char>& letters, char target) {
        int pos =  bs(letters, target)%letters.size();
        return letters[pos];
    }
};