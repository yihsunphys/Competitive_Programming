#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int maxn = 33000;
bool prime[maxn];
int main() {
    for(int i = 2; i < maxn; i++) {
        if (!prime[i]) {
            for (int j = i+i ; j < maxn; j+=i) {
                prime[j] = 1;
            }
        }
    }
    
    int n;
    while(cin >> n) {
        if(n == 0) break;
        int cnt = 0;
        for(int i = 2; i <= n/2; i++){
            if(!prime[i] && !prime[n-i]) cnt++;
        }
        cout << cnt <<endl;
    }
}
