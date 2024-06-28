#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define ll long long 
#define endl '\n' 
/*-----------------------------------*/
int main(){
   int K,Q,R;
   int a[25][25]={};
   cin>>K>>Q>>R;
   string s;
   char s_new[25][25]={};
   cin>>s;
   for(int i=0;i<Q;i++){
      for(int j=0;j<K;j++){
         cin>>a[i][j];
      }
      for(int j=0;j<K;j++){
         s_new[i][a[i][j]-1]=s[j];
      }
      for(int j=0;j<K;j++){
         s[j]=s_new[i][j];
      }  
   }
   for(int i=0;i<R;i++){
      for(int j=0;j<Q;j++){
         cout<<s_new[j][i];
      }
      cout<<endl;
   }
   return 0;
}
