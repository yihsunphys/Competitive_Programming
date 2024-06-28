#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define ll long long
#define endl '\n'
/*-------------------------------------------*/
int main(){IOS;
    int n,m,a[102][102],min;
    cin>>n>>m;
    for(int i=0;i<n+2;i++){
        for(int j=0;j<m+2;j++){
            a[i][j]=-1;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            cin>>a[i][j];
        }
    }
    min=a[1][1];
    int row=1,col=1;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(a[i][j]<min) {
                min=a[i][j];
                row=i;
                col=j;
            }
        }
    }
    int sum=a[row][col];
    a[row][col]=-1;
    while(1){
        min=1000000;
        int k=0;
        if(a[row-1][col]<min&&a[row-1][col]!=-1) {
            min=a[row-1][col];
            k=1;
        }
        if(a[row+1][col]<min&&a[row+1][col]!=-1) {
            min=a[row+1][col];
            k=2;
        }
        if(a[row][col-1]<min&&a[row][col-1]!=-1) {
            min=a[row][col-1];
            k=3;
        }
        if(a[row][col+1]<min&&a[row][col+1]!=-1) {
            min=a[row][col+1];
            k=4;
        }

        if(k==1) {
            a[row-1][col]=-1;
            row-=1;
        }
        if(k==2) {
            a[row+1][col]=-1;
            row+=1;
        }
        if(k==3) {
            a[row][col-1]=-1;
            col-=1;
        }
        if(k==4) {
            a[row][col+1]=-1;
            col+=1;
        }
        if(k==0) break;
        sum+=min;
    }
    cout<<sum;
    return 0;
}
