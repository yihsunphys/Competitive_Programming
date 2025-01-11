#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

/*---------------------------*/
int main(){IOS;
   int n,m;
   cin>>n>>m;
   while(n--){
      set <int> myset;
      int num;
      for(int i=0;i<m;i++){
         cin>>num;
         myset.insert(num);
      }
      int ans=0;
      for(int i=0;i<m;i++){
         cin>>num;
         if(myset.count(num)) ans++;
      }
      cout<<ans<<endl;
   }
   return 0;
}
