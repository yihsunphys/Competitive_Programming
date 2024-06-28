#include <bits/stdc++.h>
using namespace std;
int s[505];
int main(){
  
  int n;
  cin >> n;
  while(n--){
    int r;
    cin >> r;
    for(int i = 0; i < r; i++){
      int num;
      cin >> num;
      s[i] = num;
      //cin>>s[i];
    }
    sort(s, s+r);
    int x =  s[(r-1)/2];
    int sum = 0;
    for(int i = 0; i < r; i++)
      sum += abs(s[i]-x);
    cout << sum <<endl;
      
  }
}
//求中位數
