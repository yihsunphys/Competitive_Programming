#include <bits/stdc++.h>
using namespace std;
int n;
void solve(vector<int> h) {
  stack<int> STK;
  for (size_t i = 0; i < n; ++i) {//cout << h.size();
  while (STK.size() && h[STK.top()] < h[i]) STK.pop();
  cout << STK.size() << " ";
  STK.emplace(i);
 }
}

int main(){
  
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; i++){
    int num;
    cin >> num;
    v.emplace_back(num);
  }
  solve(v);
}
