#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  unsigned long long f,g;
  while(cin>>n){
     f=0;
     g=0;
     for(int i=1;i<=n;i++){
        f+=i;
        g+=f;
     }
  cout<<f<<" "<<g<<endl;
  }
  return 0;
}
