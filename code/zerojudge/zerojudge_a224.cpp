#include <bits/stdc++.h>
using namespace std;
int main(){
  string a,c;
  cin>>a;
  int x,count,n, y;
  n=0;
  count=0;
  x=a.size();
  for(int i=0;i<x;i++){
    cout<<int(a[i]) ;
    if(64<int(a[i])<91){
        c[n]=a[i];
        n++;
    }
    if(96<int(a[i])<123){
        c[n]=a[i];
        n++;
    }
  }

  return 0;
}
