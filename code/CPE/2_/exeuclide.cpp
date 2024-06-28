#include <bits/stdc++.h>
using namespace std;
#define ll long long
void euclidextend(ll a, ll b, ll &X, ll &Y, ll &D) {
  if(b == 0) {
    X = 1;
    Y = 0;
    D = a;
  }
  else {
    euclidextend(b, a % b, Y, X, D);
    Y -= X * (a / b);
  }
}


int main() {
  ll a, b, X, Y, D;
  while(cin >> a >> b) {
    euclidextend(a, b, X, Y, D);
    cout << X << " " << Y << " " << D << "\n";
  }

}
