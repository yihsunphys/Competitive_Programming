#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define ll long long 
#define endl '\n' 
/*-----------------------------------*/
int main(){
   int k;
   cin>>k;
   int mx=-1;
   int cnt=0,idx=0;
   for(int i=0;i<k;i++){
      int t,s;
      cin>>t>>s;
      if(s==-1) cnt++;
      if(s>mx) {
         mx=s;
         idx=t;
      }
   }
   int ans=mx-k-cnt*2;
   if(ans<0) ans=0;
   cout<<ans<<" "<<idx;
   return 0;
}
