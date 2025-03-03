class Solution {
    public:
        int candy(vector<int>& ratings) {
            vector<int> ans(ratings.size(), 1);
            for(int i = 0; i < ratings.size()-1; i++){
                if(ratings[i+1] > ratings[i]) ans[i+1] = ans[i]+1;
            }
            for(int i = ratings.size()-1; i >= 1; i--){
                if(ratings[i-1] > ratings[i]) ans[i-1] = max(ans[i]+1, ans[i-1]);
            }
            int sum = 0;
            for(int i: ans) sum+=i;
            return sum;
        }
    };