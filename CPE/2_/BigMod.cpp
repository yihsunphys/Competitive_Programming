#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define ll long long 
#define endl '\n' 
/*-----------------------------------*/
ll bg(ll B, ll P, ll M){
   if(P==0){
        return 1;
   }
   else if(P==1){
      return B%M;
   }
   else if(P%2==0){
      ll tmp=bg(B,P/2,M)%M;
      return (tmp*tmp)%M;
   }
   else{
      ll tmp=bg(B,P/2,M)%M;
      return B*(tmp*tmp)%M;
   }
}

int main(){
   int B, P, M;
   cin>>B>>P>>M;
   cout<<bg(B,P,M)<<endl;
}
