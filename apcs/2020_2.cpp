#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define ll long long
#define endl '\n'
/*-------------------------------------------*/
int main(){IOS;
    int a[100][100],temp[100][100],mi=99,ma=0;
    int r,c,k,m,cnt=0;
    cin>>r>>c>>k>>m;
    for(int i=0;i<r+2;i++){
        for(int j=0;j<c+2;j++){
            a[i][j]=-1;
            temp[i][j]=0;
        }
    }
    for(int i=1;i<r+1;i++){
        for(int j=1;j<c+1;j++){
            cin>>a[i][j];
        }
    }

    for(int z=0;z<m;z++){
       for(int i=1;i<r+1;i++){
           for(int j=1;j<c+1;j++){
                if(a[i][j]!=-1){
                    if(a[i-1][j]!=-1){
                        temp[i-1][j]+=a[i][j]/k;
                        cnt++;
                    }
                    if(a[i+1][j]!=-1){
                        temp[i+1][j]+=a[i][j]/k;
                        cnt++;
                    }
                    if(a[i][j-1]!=-1){
                        temp[i][j-1]+=a[i][j]/k;
                        cnt++;
                    }
                    if(a[i][j+1]!=-1){
                        temp[i][j+1]+=a[i][j]/k;
                        cnt++;
                    }
                    temp[i][j]-=cnt*(a[i][j]/k);
                    cnt=0;
                }
           }
       }

        for(int b=1;b<r+1;b++){
                for(int d=1;d<c+1;d++){
                    a[b][d]+=temp[b][d];
            }
        }
        for(int b=0;b<r+2;b++){
                for(int d=0;d<c+2;d++){
                    temp[b][d]=0;
            }
        }  
        
    }
    for(int i=1;i<r+1;i++){
        for(int j=1;j<c+1;j++){
            if(a[i][j]>ma&&a[i][j]>0) ma=a[i][j];
            if(a[i][j]<=mi&&a[i][j]>-1) mi=a[i][j];
        }
    }
    cout<<mi<<endl<<ma;
    return 0;
}
