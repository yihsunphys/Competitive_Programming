#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define ll long long
#define endl '\n'
/*--------------------------------------*/
//想法:建質數表 v
vector <int> v;
const int ma=1005;
int prime[ma];

int main(){
   prime[0]=1;
   int p=2;
   v.push_back(1);
   while(p<=ma){
      if(!prime[p]){
         v.push_back(p);
         for(int i=p;i<ma;i+=p) prime[i]=1;
      }
      p++;
   }
//二分搜找質數
int N, K, C;
   while(cin>>N>>C){
      auto it=lower_bound(v.begin(),v.end(),N);
      K=int(it-v.begin());
      if(*it==N) K++;
      cout<<N<<" "<<C<<":";
      for (int i=max(0,K/2-C+(K%2));i<min(K,K/2+C);i++){
         cout<<' '<<v[i];
      }
      cout<<endl;
   }
   return 0;
}
