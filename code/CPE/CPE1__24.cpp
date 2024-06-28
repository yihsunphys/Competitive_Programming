#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535
int main(){
  double a, b;
  string s;
  while(cin >> a >> b >> s) {
    a+=6440;
    if(s == "min") b/=60;
    cout << fixed << setprecision(6) << 
    a*(b)/180*pi << " " << 2*a*sin(b/360*pi)<<'\n';
  }
}
