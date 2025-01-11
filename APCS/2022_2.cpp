#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define ll long long
#define endl '\n'
/*----------------------------*/
int main(){
   int R,C,n,a[35][55]={},cnt=0,cnt2=0;
   char t;
   int y;
   cin>>R>>C>>n;
   while(n--){
      cin>>t>>y;
      bool k=0;
      if(t=='B'){
         int j=-1;
         for(int i=C-3;i>=0;i--){   
            if(a[R-y-1][i]==0&&a[R-y-1][i+1]==0&&a[R-y-1][i+2]==0){               
                  j=i;
            }
            else break;
         }
         if(j!=-1){
            a[R-y-1][j]=1;a[R-y-1][j+1]=1;a[R-y-1][j+2]=1;
            k=1;
         }  
      }
      if(t=='A'){
         int j=-1;
         for(int i=C-1;i>=0;i--){   
            if(a[R-y-1][i]==0&&a[R-y-2][i]==0&&a[R-y-3][i]==0&&a[R-y-4][i]==0){
                  j=i;                 
            }
            else break;
         }  
         if(j!=-1){
            a[R-y-1][j]=1;a[R-y-2][j]=1;a[R-y-3][j]=1;a[R-y-4][j]=1;
            k=1;
         }
      }
      if(t=='C'){
         int j=-1;
         for(int i=C-2;i>=0;i--){   
            if(a[R-y-1][i]==0&&a[R-y-1][i+1]==0&&a[R-y-2][i]==0&&a[R-y-2][i+1]==0){
                  j=i;
            }
            else break;
         } 
         if(j!=-1){
           a[R-y-1][j]=1;a[R-y-1][j+1]=1;a[R-y-2][j]=1;a[R-y-2][j+1]=1;
           k=1;
         }
      }

      if(t=='D'){
         int j=-1;
         for(int i=C-3;i>=0;i--){   
            if(a[R-y-1][i+2]==0&&a[R-y-2][i]==0&&a[R-y-2][i+1]==0&&a[R-y-2][i+2]==0){
                  j=i;
            }
            else break;
         } 
         if(j!=-1){
           a[R-y-1][j+2]=1;a[R-y-2][j]=1;a[R-y-2][j+1]=1;a[R-y-2][j+2]=1;
           k=1;
         }
      }

      if(t=='E'){
         int j=-1;
         for(int i=C-2;i>=0;i--){   
            if(a[R-y-1][i+1]==0&&a[R-y-2][i]==0&&a[R-y-2][i+1]==0&&a[R-y-3][i]==0&&a[R-y-3][i+1]==0){
                  j=i;
            }
            else break;
         } 
         if(j!=-1){
           a[R-y-1][j+1]=1;a[R-y-2][j]=1;a[R-y-2][j+1]=1;a[R-y-3][j]=1;a[R-y-3][j+1]=1;
           k=1;
         }
      }
      





      if(k==0){
         cnt++;
      }


   }
   for(int i=0;i<R;i++){
      for(int j=0;j<C;j++){
         if(a[i][j]==0) {
            cnt2++;
         }
      }
   }
   cout<<cnt2<<" "<<cnt;
   return 0;
}
