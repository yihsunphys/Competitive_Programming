#include <bits/stdc++.h>
using namespace std;

int a[1000000], b[1000000], c[1000000];
int main() {
  int N;
  scanf("%d", &N);
  int M;
  
  while(N--){
    scanf("%d", &M); 
    for(int i = M-1; i >= 0; i--) {
      scanf("%d%d",&a[i], &b[i]);
    }

    int sum = 0, carry = 0;
    for(int i = 0; i < M; i++) {
      sum = a[i] + b[i] + carry;
      c[i] = sum % 10;
      carry = sum / 10;
    }
    for(int i = M-1; i >= 0; i--)
      printf("%d", c[i]);
    printf("%c",'\n');
  }
}
