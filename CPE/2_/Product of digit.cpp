#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while(n--) {
    int num;
    cin >> num;
    if(num == 1) {
      cout << 1 <<endl;
      continue;
    }
    int a[10] = {};
    for(int i = 2; i < 10; i++) {
      while(num%i == 0) {
        a[i]++;
        num /= i;
      }
    }
    if(num != 1) cout << -1 << endl;
    else{
      a[8] += a[2]/3;
      a[2] = a[2]%3;
      a[9] += a[3]/2;
      a[3] = a[3]%2;
      int mi = min(a[3], a[2]);
      a[6] += mi; a[3] -= mi; a[2] -= mi;
      a[4] += a[2]/2; a[2]=a[2]%2;
      for(int i = 2; i < 10; i++) {
        while(a[i]--) cout << i; 
      }
      cout<<endl;
    } 
  }
}
/*-------------------------------------------------------*/
一開始從2開始做因數分解 之後還要將2轉成8 3轉成9 浪費時間
直接從9開始檢查是否為因數就好了
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, num;
  cin >> n;
  while(n--) {
    cin >> num;
    if(num == 1) {
      cout << 1 <<endl;
      continue;
    }
    int a[10] = {};
    for(int i = 9; i >=2 ; i--) {
      while(num%i == 0) {
        a[i]++;
        num /= i;
      }
      if(num == 1) break;
    }
    if(num != 1) cout << -1 << endl;
    else{
      for(int i = 2; i < 10; i++) {
        while(a[i]--) cout << i; 
      }
      cout<<endl;
    } 
  }
}
