#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> top;
  while(n--) {
    int x;
    cin >> x;
    int lo = 0, hi = top.size();
    while(lo<hi) {
        int mid = (lo+hi)/2;
        if(top[mid]>x) hi = mid;
        else lo = mid+1;
    }
    if(lo == top.size()) {
        top.push_back(x);
    }
    else top[lo] = x;
  }
  cout << top.size();
}
