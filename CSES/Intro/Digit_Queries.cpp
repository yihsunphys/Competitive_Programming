#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll power(ll a, ll b){
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a);
        }
        a = (a * a);
        b >>= 1;
    }
    return res;
}
int main() {
  ll n;
  cin >> n;
  while(n--) {
    ll num;
    cin >> num;

    ll digit = 1, x = 9;
    while(num-digit*x>0) {
        num-=digit*x;
        digit++;
        x*=10;
    }
    ll y = power(10, digit-1) + (num-1)/digit;
    ll z = num%digit;
    if (z != 0)
        y = y / power(10, digit - z);
    cout<< y % 10 << '\n';
  }
}