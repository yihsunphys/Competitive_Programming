#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,N,c=0;
    char a;
    cin>>n;
    while(n--){
            c++;
        cin>>a>>a>>N;
        long long a[N][N]={};
        int flag=0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin>>a[i][j];
            }
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(a[i][j]!=a[N-i-1][N-j-1]||a[i][j]<0) {
                        flag=1;
                        break;
                }
            }
        }
        cout<<"Test #"<<c;
        if(flag==0) cout<<": Symmetric."<<endl;
        else cout<<": Non-symmetric."<<endl;
    }
}
