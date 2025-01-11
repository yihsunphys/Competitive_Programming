#include <bits/stdc++.h>
using namespace std;
int main(){
  int x, y,a[5];
  cin>>x;
  for(int i=0;i<x;i++){
    cin>>a[0]>>a[1]>>a[2]>>a[3];
    if(a[2]-a[1]==a[1]-a[0])  a[4]=a[3]+(a[2]-a[1]);
    else a[4]=a[3]*(a[1]/a[0]);
    for(int j=0;j<5;j++)
            cout<<a[j]<<" ";
    cout<<endl;
  }
  return 0;
}
