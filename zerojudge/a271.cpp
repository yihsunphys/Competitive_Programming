#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define ll long long
#define endl '\n'
/*-----------------------------------------*/
int main(){IOS;
   int x,y,z,w,n,m;
   int r;
   cin>>r;
   while(r--){
      cin>>x>>y>>z>>w>>n>>m;
      string s;
      cin.ignore();
      getline(cin,s);
      //cout<<s<<endl;
      stringstream ss(s);
      int a;
      int k=0;
      while(ss>>a){
         //cout<<m;
         /*if(m<=0){
            cout<<"bye~Rabbit\n";
            break;
         }*/
         m-=k*n;
         if(m<=0){
            cout<<"bye~Rabbit\n";
            break;
         }
         if(a==1) m+=x; 
         if(a==2) m+=y;
         if(a==3) m-=z;
         if(a==4) {
            m-=w;
            k++;
         }
         if(m<=0){
            cout<<"bye~Rabbit\n";
            break;
         }
      }
      //cout<<m;
      if(m>0) cout<<m<<"g\n";
   }
}
