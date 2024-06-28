#include <bits/stdc++.h>
using namespace std;
int main(){
  int a[3];
  for(int i=0;i<3;i++)
    cin>>a[i];
  if(a[0]==0) a[0]=0;
  else a[0]=1;
  if(a[1]==0) a[1]=0;
  else a[1]=1;
  int k=0;
  if((a[0]&&a[1])==a[2]) {
    cout<<"AND"<<endl;k++;
  }
  if ((a[0]||a[1])==a[2]){
        cout<<"OR"<<endl;k++;
  }
  if((a[0]^a[1])==a[2]){
         cout<<"XOR"<<endl;k++;
  }
  if (k==0)
          cout<<"IMPOSSIBLE"<<endl;
  return 0;
}
