#include <bits/stdc++.h>
using namespace std;
int main(){
  string a,b;
  cin>>a;
  int x,i;
  int count;
  count=0;
  x=a.size();

  for(i=x;i>0;i--){
    if(a[i-1]!='0'){
       break;
    }
    count++ ;
  }
  if(a[0]=='0'){
    b[0]='0';
  }
  else{
    for(i=0;i<x;i++){
      int y=x-count;
      b[i]=a[y-i-1];
    }
  }
  for(i=0;i<x;i++){
      cout<<b[i];
  }   
  return 0;
}
