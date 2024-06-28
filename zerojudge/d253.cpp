#include <bits/stdc++.h>
using namespace std;
/*--------------------*/
int coin[5] = {1, 5, 10, 25, 50};
int dp[5][7500];

int way(int idx, int money){
    if(money == 0) return 1;
    if(dp[idx][money] != -1) return dp[idx][money];
    int ret = 0;
    for(int i = idx; i<5; i++){
        if(money >= coin[i]) ret +=way(i, money - coin[i]);
    }
    return dp[idx][money] = ret;
}
int main(){
    int n;
    memset(dp, -1, sizeof(dp));
    while(cin >> n){
        cout << way(0, n) << "\n";
    }
}
