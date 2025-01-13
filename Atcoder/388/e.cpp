// binary search 看最大值
// for k, 優先配對最大k個 看能不能配對完
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

// 檢查是否可以成功配對 k 對
bool isok(int k) {
    int left = 0;         // 左指針，表示較小的數
    int right = n - k;    // 右指針，表示較大的數
    for (int i = 0; i < k; ++i) {
        // 如果最小的數無法配對，則返回 false
        if (a[left] * 2 > a[right]) return false;
        ++left;
        ++right;
    }
    return true; // 可以成功配對 k 對
}

int main() {  
  cin >> n;
  a.resize(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  int l = 0, r = n/2;
  while(l<=r){
    int m = l+(r-l)/2;
    if(isok(m)) {
      l=m+1;
    }
    else r=m-1;
  }
  cout << r;
}

