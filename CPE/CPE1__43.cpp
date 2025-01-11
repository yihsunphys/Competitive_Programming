#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  while(cin>>n){
      int sum=n;
      int x=0;
    while(1){
        x=n%3;
        n=(n-x)/3;
        sum+=n ;
       n=n+x;
       if(n<3) break;
    }
    if(n==2) cout<<sum+1<<endl;
    else  cout<<sum<<endl;

  }
  return 0;
}
