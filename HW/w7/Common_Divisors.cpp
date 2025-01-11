#include <bits/stdc++.h>
using namespace std;
int a[200005], cnt[1000005];
int main(){
  int n;
  cin >> n;
  memset(cnt, 0, sizeof(cnt));
  for(int i = 0; i < n; i++){
    cin >> a[i];
    cnt[a[i]]++;
  }
  for(int i = 1000005; i >= 1; i--){
    int div = 0;
    for(int j = i; j < 1000005; j += i){
      div += cnt[j]; //j為因數的數量
    }
    if(div > 1){ //代表至少為兩個數的公因數
      cout << i << endl;
      return 0;
    }
  }
}