#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define ll long long
#define endl '\n'
/*--------------------------------------*/
int main(){IOS;
   int K,Q,N;
   while(cin>>K>>Q>>N){
      if(K==Q){
         cout<<"Illegal state\n";
         continue;
      }
      int qx,qy,kx,ky,nx,ny;
      qy=Q/8;qx=Q%8;ky=K/8;kx=K%8;ny=N/8;nx=N%8;
      if(qx!=nx&&qy!=ny){
         cout<<"Illegal move\n";
         continue;
      }
      if(Q==N||N==K){
         cout<<"Illegal move\n";
         continue;
      }
      if(qy==ny&&ky==ny){
         if(nx<qx&&nx<kx&&kx<qx){
            cout<<"Illegal move\n";
            continue;
         }
         if(nx>qx&&nx>kx&&kx>qx){
            cout<<"Illegal move\n";
            continue;
         }
      }
      if(qx==nx&&kx==nx){
         if(ny>qy&&ny>ky&&ky>qy){
            cout<<"Illegal move\n";
            continue;
         }
         if(ny<qy&&ny<ky&&ky<qy){
            cout<<"Illegal move\n";
            continue;
         }
      }
      if(nx==kx){
         if(abs(ny-ky)<2){
            cout<<"Move not allowed\n";
            continue;
         }
      }
      if(ny==ky){
         if(abs(nx-kx)<2){
            cout<<"Move not allowed\n";
            continue;
         }
      }


      bool flag=0;
      if(kx+1<8&&kx+1!=nx&&ky!=ny) flag=1;
      if(kx-1>=0&&kx-1!=nx&&ky!=ny) flag=1;
      if(ky+1<8&&kx!=nx&&ky+1!=ny) flag=1;
      if(ky-1>=0&&kx!=nx&&ky-1!=ny) flag=1;
      if(flag) cout<<"Continue\n";
      else cout<<"Stop\n";
   }
   return 0;
}
