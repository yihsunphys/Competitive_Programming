#include <bits/stdc++.h>
using namespace std;
#define ll long long
int bit[100];
int n;
int lowbit(int x) {
  return x & -x;
}
void modify(int pos, int x){ 
    for(; pos <= n; pos += lowbit(pos)){
        bit[pos] += x;
    }
}
ll query(int pos){
    ll ans;
    for(; pos > 0; pos -= lowbit(pos)){
        ans += bit[pos];
    }
    return ans;
}
int main() {
  cin >> n;
}