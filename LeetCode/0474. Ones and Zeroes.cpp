// 01背包 字串是物品 重量有二維
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(auto str: strs){
            int num_of_0 = 0, num_of_1 = 0;
            for(auto ch: str){
                if(ch=='0') num_of_0++;
                if(ch=='1') num_of_1++;
            }
            for(int i = m; i >= num_of_0; i--){
                for(int j = n; j >= num_of_1; j--){                
                    dp[i][j] = max(dp[i][j], dp[i-num_of_0][j-num_of_1]+1);
                }
            }
        }
        return dp[m][n];
    }
};