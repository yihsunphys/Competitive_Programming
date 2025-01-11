#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int length[3005][3005];
int LCS[3005][3005]; 
void printLCS_recursive(int i, int j) {
  if (i == 0 || j == 0) return;
  if (LCS[i][j] == 0) {
    printLCS_recursive(i - 1, j - 1);
    cout<<s1[i-1];
  }
  else if (LCS[i][j] == 1)  printLCS_recursive(i, j - 1);
  else  printLCS_recursive(i - 1, j);
}

int findLCS(int n1, int n2){
  for (int i = 0; i <= n1; ++i)
    length[i][0] = 0;
  for (int j = 0; j <= n2; ++j)
    length[0][j] = 0;

  for (int i = 1; i <= n1; ++i) {
    for (int j = 1; j <= n2; ++j) {
      if (s1[i-1] == s2[j-1]) {
        length[i][j] = length[i - 1][j - 1] + 1;
        LCS[i][j] = 0;
      }
      else if (length[i - 1][j] < length[i][j - 1]) {
        length[i][j] = length[i][j - 1];
        LCS[i][j] = 1;
      }
      else {
        length[i][j] = length[i - 1][j];
        LCS[i][j] = 2;
      }
    }
  }
  printLCS_recursive(n1, n2);
  return length[n1][n2];
}

int main(){
  int n1, n2;
  cin >> s1 >> s2;
  n1 = s1.size(), n2 = s2.size();
  findLCS(n1, n2);
}