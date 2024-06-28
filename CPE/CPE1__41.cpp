#include <bits/stdc++.h>
using namespace std;
int a[40];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int Case;
  cin >> Case;
  for(int i = 1; i <= Case; i++) {
    cout << "Case "<<i<<":\n";
    for(int i = 0; i <= 35; i++)
      cin >> a[i];
    int Case2;
    cin >> Case2;
    while(Case2--) {
      int num;
      cin >> num;
      cout << "Cheapest base(s) for number ";
      cout << num << ':';
      int ans = 1000000000;
      int base[40] = {};
      for(int i = 2; i <= 36; i++) {
        int sum = 0;
        int dec = num;
        while(dec) {
          sum += a[dec%i];
          dec /= i;
        }
        base[i] = sum;
        if(sum <= ans) {
          ans = sum;
        }
      }
      for(int i = 2; i <= 36; i++){     
        if(base[i] == ans) {
          cout<<" ";
          cout << i;
        }
      }
      cout << '\n';
    }
    if(i != Case) cout<<'\n';
  }
}
