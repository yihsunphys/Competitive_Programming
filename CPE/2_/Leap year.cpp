#include <bits/stdc++.h>
using namespace std;
bool isfour(string s) {
  int n = s.size();
  int sum = (s[n-1]-'0') + 10*(s[n-2]-'0');
  if(sum%4 == 0) return true;
  else return false;
}
bool ishundred(string s) {
  int n = s.size();
  if(s[n-1] == '0' && s[n-2] =='0') return true;
  else return false;
}
bool isfourhundred(string s) {
  int n = s.size();
  int sum = (s[n-1]-'0') + (s[n-2]-'0')*10 +(s[n-3]-'0')*100 +(s[n-4]-'0')*1000;
  if(sum%400 == 0) return true;
  else return false;
}
bool isfifteen(string s) {
  int sum = 0;
  int n = s.size();
  for(int i = 0; i < s.size(); i++) {
    sum += s[i]-'0';
  }
  if(sum%3 == 0 && (s[n-1] == '0' || s[n-1] == '5') ) return true;
  else return false;
}

bool isfifteenfive(string s) {
  int n = s.size();
  int sum1 = 0, sum2 = 0;
  for(int i = 0; i < n; i += 2)
    sum1 += s[i]-'0';
  for(int i = 1; i < n; i += 2)
    sum2 += s[i]-'0';
  if((sum1 - sum2) % 11 == 0 && (s[n-1] == '0' || s[n-1] == '5') )
    return true;
  else return false;
  
}
bool isleap(string s) {
  if(isfour(s)){
      if(ishundred(s)){
        if(isfourhundred(s)){
          return true;
        }
        else return false;
      }
      else return true;
  }
  else return false;
}


int main() {
  string s;
  while(cin >> s) {
    bool ordinary = true;
    if(isleap(s)){
        cout<<"This is leap year.\n";
        ordinary = false;
    }
 
    if(isfifteen(s)) {
      cout<<"This is huluculu festival year.\n";
      ordinary = false;
    }
    if(isfifteenfive(s) && isleap(s)) {
      cout<<"This is bulukulu festival year.\n";
      ordinary = false;
    }
    if(ordinary) cout<<"This is an ordinary year.\n";
    cout<<'\n';
  }

}
