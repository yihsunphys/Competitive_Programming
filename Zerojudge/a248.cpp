#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define endl '\n'
/*----------------------------*/
int main(){IOS;
   int a,b,N;
   while(cin>>a>>b>>N){
      if(N) cout<<a/b<<'.';
      for(int i=0;i<N;i++){
       a=(a%b*10);
       if(a==0){for(int j=i;j<N;j++) cout<<0;break;}
       cout<<a/b;  
      }
      cout<<endl;
   }
}
