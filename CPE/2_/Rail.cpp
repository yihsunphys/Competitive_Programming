#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define ll long long
#define endl '\n'
/*---------------------------------------------------------*/
int main(){IOS;
   int n;
   while(cin>>n&&n){
      while(1){ //point 是排隊等待進入的車輛
         stack <int> stk; int a[n]; int point=1;
         cin>>a[0];
         if(a[0]==0){
            cout<<endl;
            break;
         }
         for(int i=1;i<n;i++) cin>>a[i];
         int i;
         for(i=0;i<n;i++){
            if(!stk.empty()&&stk.top()==a[i]) stk.pop();
            else if(a[i]>=point){
               for(int j=point;j<a[i];j++) stk.push(j);
               point=a[i]+1;
            }
            else break;
         }
         if(i==n) cout<<"Yes"<<endl;
         else cout<<"No"<<endl;
      }
   }
   return 0;
}
