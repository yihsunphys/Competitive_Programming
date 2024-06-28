#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  while(n--) {
    cin >> s;
    int dig_coef = 0, x_coef = 0;
    int neg = 1, left = 1;
    int tmp = 0;
    bool has_num = false;
    for(int i = 0; i < s.size(); i++) {
      if(s[i] == 'x') {
        if(tmp == 0 && !has_num) tmp = 1;
        x_coef += left*neg*tmp;
        tmp = 0;
        has_num = false;
      }
      else if(s[i] == '+') {
        dig_coef += left*neg*tmp;
        tmp = 0;
        neg = 1;
        has_num = false;
      }
      else if(s[i] == '-') {
        dig_coef += left*neg*tmp;
        tmp = 0;
        neg = -1;
        has_num = false;
      }
      else if(s[i] == '=') {
        dig_coef += left*neg*tmp;
        tmp = 0;
        neg = 1;
        left = -1;
        has_num = false;
      }
      else {
        tmp *= 10;
        tmp += s[i] -'0';
        has_num = true;
      }
    }
    dig_coef += neg*left*tmp;
    if(x_coef == 0 && dig_coef==0) cout << "IDENTITY\n";
    else if(x_coef == 0 && dig_coef!=0) cout << "IMPOSSIBLE\n";
    else {
      cout << (int)floor((double)(-dig_coef)/(double)x_coef) <<'\n';
    }
  }
}
