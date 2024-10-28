#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,x,y,vx,vy;
void exgcd(ll a,ll b,ll &x,ll &y) { 
  if (!b) x=1,y=0;
  else exgcd(b,a%b,y,x),y-=a/b*x; 
}
int main() {
  int t;
  cin >> t;
  while(t--){
	cin >> n >> m >> x >> y >> vx >> vy;
	if (vx==0){
		x==0 || x==n ? cout << x << (vy>0)*m : cout << "-1";
		continue;
	}
	if (vy==0){
      y==0||y==m ? cout << (vx>0)*n << y : cout << "-1";
	  continue;
	}
	if (vx<0) vx=1,x=n-x; else vx=0;
	if (vy<0) vy=1,y=m-y; else vy=0;
	if ((x-y)%__gcd(n,m)) return puts("-1"),0;
	ll A,B,g=__gcd(n,m),mod=m/g;
	exgcd(n,-m,A,B),A*=(x-y)/g,B*=(x-y)/g;
	if (x-y!=A*n-B*m) A=-A,B=-B;
	ll AA=((A+mod-1)%mod+mod)%mod+1,BB=(AA*n-x+y)/m;
	vx^=AA&1,vy^=BB&1;
	return printf("%d %d\n",vx?n:0,vy?m:0),0;
  }
}