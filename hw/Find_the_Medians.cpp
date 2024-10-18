#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  int num;
  for(int i = 0; i < n; i++){
    cin >> num;
    v.push_back(num);
    nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
    int m1 = *(v.begin() + v.size() / 2);
    int m2 = 0;
    if(i%2 == 0) {
      nth_element(v.begin(), v.begin() + v.size() / 2-1, v.end());
      m2 = *(v.begin() + v.size() / 2-1);
    }
    cout << (m1 + m2) / 2 << '\n';
  }
}