#include <bits/stdc++.h>
using namespace std;
int main(){
  string a;
  cin>>a;
  int x,count,i;
  count=0;
  x=a.size();
  for(i=0;i<x/2;i++){
    if (a[i]!=a[x-1-i]){
        count++;
    }
  }
  if(count!=0){
    cout<<"no";
  }
  else{
    cout<<"yes";
  }
  return 0;
}
