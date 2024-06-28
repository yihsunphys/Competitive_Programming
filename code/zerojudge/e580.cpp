#include <bits/stdc++.h> 
using namespace std;
int main() {
    int n, m, a, b, ans = 0;
    while(cin >> n >>m) {
        if (n ==0 && m == 0) break;
        a = min(n ,m);
        b = max(n, m);
        if(a == 1) ans=b;
        else if(a ==2){
            ans = (max(n, m)/4) * 2;
            ans += min(max(n, m)%4, 2);
            ans *= 2;
        }
        else  ans = a*b/2+a*b%2;
        cout << ans <<" knights may be placed on a " << n <<" row " << m << " column board.\n";
    }
}
