#include <bits/stdc++.h>
using namespace std;    

//bool is_prime[100005];
void sieve(int n) {
  //先設每一個數字都是質數
  memset(is_prime, true, sizeof(is_prime));
  //0和1不是質數
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

// Sieve Of Euler
vector<int> prime;
vector<bool> is_prime;
void seive(int n){
  prime.clear();
  is_prime.assign(n+1, 1);
  is_prime[0] = is_prime[1] = 0;
  for(int i = 2; i < n; i++){
    if(is_prime[i]) prime.push_back(i);
    for(auto p: prime){
      if(1LL*i*p > n) break;
      is_prime[i*p] = 0;
      if(i%p == 0) break;
    }
  }
}

//篩法求 1~𝑛 每個數的質因數分解
vector<vector<int>> prime_factor(n+1);
for(int i = 2; i <= n; i++){
  if(prime_factor[i].empty()){
    for(int j = i; j <= n; j+=i) {
      prime_facor[j].push_back(i);
    }
  }
}
void prime_factor_print(int x){
  int tmp = x;
  for(auto p: prime_factor[x]){
    int cnt = 0;
    for(; tmp%p == 0; tmp/=p, cnt++);
    cout << p << "^" << cnt << " ";
  }
}

