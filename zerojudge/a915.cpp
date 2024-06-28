#include <bits/stdc++.h>
using namespace std;
/*-----------------------------*/
struct pt{
  int x,y;
};
bool cmp(pt a, pt b){
  if(a.x==b.x){
    return a.y<=b.y;
  }
  else return a.x<b.x;
}
int main(){
   int n;
   cin>>n;
   pt a[1005];
   for(int i=0;i<n;i++){
      cin>>a[i].x>>a[i].y;
   }
   sort(a,a+n,cmp);
   for(int i=0;i<n;i++){
      cout<<a[i].x<<" "<<a[i].y<<endl;
   }
}
