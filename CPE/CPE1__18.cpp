#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  while(getline(cin,s)) {
    int sum = 0;
    int mx = 1;
    for(int i = 0; i < s.size(); i++) {
      int tmp;
      if(isdigit(s[i])){
        tmp = s[i] - '0';
      }
      else if(isupper(s[i])) {
        tmp = s[i] - 'A' + 10;
      }
      else if(islower(s[i])) {
        tmp = s[i] - 'a'+ 36;
      }
      else continue;
      sum += tmp;
      if(tmp > mx)
        mx = tmp;
    }
    int i; 
    for(i = mx; i < 62; i++) {
      if(!(sum % i)) {
        cout << i+1 <<'\n';
        break;
      }
    }
    if(i == 62) cout << "such number is impossible!\n";
  }
}
// i 從 mx 開始找
