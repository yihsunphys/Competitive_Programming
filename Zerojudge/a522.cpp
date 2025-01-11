#include <bits/stdc++.h>
using namespace std;
int s[100];
int d[1001][1001];
int cse;
int stick, len;
int main() {
  cin >> cse;
  while(cse--){
    cin >> len >> stick;
    for(int i = 0; i < stick; i++)
      cin >> s[i];
    //int d[stick+1][len+1];
    memset(d, 0, sizeof(d));
    bool flag =0;
    for(int i = 0; i < stick; i++) {
      for(int j = 0; j <= len; j++) {
        //cout << i <<" "<< j <<" "<<d[i][j] << '\n';
        if(d[i][j] == len) flag = 1;
        if(s[i] > j) d[i+1][j] = d[i][j];
        else
            d[i+1][j] = max(d[i][j], s[i] + d[i][j-s[i]]);
      }
    }
    //cout << d[stick][len] << '\n';
    if(d[stick][len] == len || flag) cout <<"YES\n";
    else cout << "NO\n";
  }
}
