#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*------------------------------*/
int a,b,c,d;

struct matrix{
    ll mat[100][100];
    matrix(){
       memset(mat,0,sizeof(mat));
    }
};

matrix mul(matrix x, matrix y){
   matrix z;
   for(int i=0;i<a;i++){
      for(int j=0;j<d;j++){
         for(int k=0;k<b;k++){
            z.mat[i][j]=z.mat[i][j]+x.mat[i][k]*y.mat[k][j];
         }
      }
   }
   return z;
}

int main(){
   while(cin>>a>>b>>c>>d){
      if(b!=c) cout<<"Error"<<endl;
      else{
         matrix m1,m2;
         for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
               cin>>m1.mat[i][j];
            }
         }
         for(int i=0;i<c;i++){
            for(int j=0;j<d;j++){
               cin>>m2.mat[i][j];
            }
         }
         matrix ans=mul(m1,m2);
         for(int i=0;i<a;i++){
            for(int j=0;j<d;j++){
               cout<<ans.mat[i][j]<<" \n"[j==d-1];
            }
         }
      }
   }
}
