// use 3 dp array
#define ll long long
#define mod 1000000007
class Solution {
public:
    int numTilings(int n) {
        vector<ll> dp(n+1), t(n+1), b(n+1);
        dp[0] = 1; dp[1] = 1; t[1] = 0; b[1] = 0;
        for(int i = 2; i <= n; i++){
            dp[i] = (dp[i-1] + dp[i-2] + t[i-1] + b[i-1])%mod;
            t[i] = dp[i-2] + b[i-1];
            b[i] = dp[i-2] + t[i-1];
        }
        return dp[n]%mod;
    }
};