#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define ll long long 
#define endl '\n'
/*-----------------------------*/
int ans=0;int sol=0;int n;
int a[30]={},b[30]={};
int f=0;
void print(){
  for(int i=0;i<f;i++){
    cout<<b[i]<<" ";
  }
  cout<<endl;
}
bool k=0;

void dfs(int idx){
  if(ans==sol) {
    print();
    k=1;
  }
  else if(idx==n) return;
  else if(ans>sol) return;
  else{
    ans+=a[idx];
    b[f]=a[idx];f++;
    dfs(idx+1);
    ans-=a[idx];
    f--;
    dfs(idx+1);
  }
}



int main(){
   cin>>n>>sol;
   for(int i=0;i<n;i++){
     cin>>a[i];
   }
   sort(a,a+n);
   dfs(0);
   if(!k) cout<<"-1";
}
