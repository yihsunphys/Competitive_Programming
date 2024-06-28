#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define endl '\n'
/*-------------------------------*/
int s1[105], s2[105];
int length[105][105];
int LCS[105][105];  // 記錄每一格的的結果是從哪一格而來
/* Recursive version */
void printLCS_recursive(int i, int j) {
    // End of null set
    if (i == 0 || j == 0) return;
    if (LCS[i][j] == 0) {
        printLCS_recursive(i - 1, j - 1);
        cout<<s1[i];
    }
    else if (LCS[i][j] == 1)
        printLCS_recursive(i, j - 1);
    else
        printLCS_recursive(i - 1, j);
}

int findLCS(int n1, int n2){
  for (int i = 0; i <= n1; ++i)
        length[i][0] = 0;
    for (int j = 0; j <= n2; ++j)
        length[0][j] = 0;
    
    // Start
    for (int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= n2; ++j) {
            if (s1[i] == s2[j]) {
                length[i][j] = length[i - 1][j - 1] + 1;
                // LCS from the left-top
                LCS[i][j] = 0;
            }
            else {
                if (length[i - 1][j] < length[i][j - 1]) {
                    length[i][j] = length[i][j - 1];
                    LCS[i][j] = 1;
                }
                else {
                    length[i][j] = length[i - 1][j];
                    LCS[i][j] = 2;
                }
            }
        }
    }
    // Print the result
    //cout<<length[n1][n2];
    //cout<<" LCS (Recursive): ";
    //printLCS_recursive(n1, n2);
    return length[n1][n2];
}

int main(){IOS;
    int n,m;
    int idx=0;
    while(cin>>n>>m){
    if(n==0&&m==0) break;
    idx++;
    s1[0]=0;s2[0]=0;
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
