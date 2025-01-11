#include <bits/stdc++.h>
using namespace std;
int main() {
  bool prime[100000];
  vector<int> v;
  for(int i = 2; i<=100000; i++) {
    if(!prime[i]){
      for(int j =2; i * j <= 100000; j++)
        prime[i*j] = 1;
      v.push_back(i); 
    }
  }
  
  

  int n;
  while(cin >> n) {
    if(n == 0) break;
    int cnt = 0;
    for (int i = 0; v[i] <= n; i++) {
      int sum =0;
      for(int j = i; sum < n; j++) {
        sum += v[j];
        if(sum == n) {
          cnt++;
          break;
        }
      }
    }
    cout << cnt <<'\n';
  }

}
//用前綴和應該能更加快速度
