#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

/*---------------------------*/
int main(){IOS;
   int n;
   cin>>n;
   set <string> c;
   string s;
   while(n--){
      cin>>s;
      c.insert(s);
   }
   int q;
   cin>>q;
   while(q--){
      cin>>s;
      if(!c.count(s)){ 
         c.insert(s);
         cout<<"no\n";
         }
      else cout<<"yes\n";
   }
}
