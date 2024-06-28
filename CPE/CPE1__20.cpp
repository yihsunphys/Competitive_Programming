#include <bits/stdc++.h>
using namespace std;
int main(){
   long long a,b;
   while(cin>>a>>b){
        int i=1;
      while(i){
      b-=a++;
       if(b<=0){
        cout<<a-1<<endl;
        break;
       }
       i++;
      }
   }
   return 0;
}
/*--------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll n, m;
  while(cin>>n>>m){
    ll sum = n;
    ll day =1;
    while(sum<m){
      sum+=n+day;
      day++;
    }
    cout<<day+n-1<<'\n';
  }
}
