#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define endl '\n'
/*-------------------------------*/
int s1[105], s2[105];
int length[105][105];
int findLCS(int n1, int n2){
    memset(length, 0, sizeof(length));
    for (int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= n2; ++j) {        
            if (s1[i] == s2[j])   length[i][j] = length[i - 1][j - 1] + 1;
            else length[i][j] = max(length[i][j-1], length[i-1][j]);
        }
    }
    return length[n1][n2];
}

int main(){IOS;
    int n,m;
    int idx=0;
    while(cin>>n>>m){
    if(n==0&&m==0) break;
    idx++;
    for(int i=1;i<=n;i++){
        cin>>s1[i];
    }
    for(int i=1;i<=m;i++){
        cin>>s2[i];
    }
    cout<<"Twin Towers #"<<idx<<endl;
    cout<<"Number of Tiles : "<<findLCS(n,m)<<endl;
    }
}
