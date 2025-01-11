#include <bits/stdc++.h>
using namespace std;
int main(){
  string a;
  cin>>a;
  int change[26]{10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33};
  int x=change[a[0]-'A'];
  int y,z,s;
  z=x%10;
  y=(x-z)/10;
  int sum;
  for(int i=1;i<9;i++){
    s+=(a[i]-'0')*(9-i);
  }
  sum=y+z*9+s+a[9]-'0';
  int q;
  q=sum%10;
  if (q==0){
    cout<<"real"<<endl;
  }
  else{
     cout<<"fake"<<endl;
  }  
  return 0;
}
