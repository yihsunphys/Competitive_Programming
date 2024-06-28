#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,x,y;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)  cin>>a[i];
  sort(a, a+n);
  for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
  cout<<endl;
  for(int k=0;k<n;k++){
    if (a[k]>=60){
      x=a[k];
      break;
    }
  }
  for(int j=n-1;j>=0;j--) {
    if (a[j]<60){
      y=a[j];
      break;
    }
  }

  if (a[n-1]<60) cout<<y<<endl<<"worst case";
  else if(a[0]>=60) cout<<"best case"<<endl<<x;
  else cout<<y<<endl<<x<<endl;
  return 0;
}
