#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define ll long long
/*-------------------------*/
int main() {//IOS;
    ll n, D, I, pos;
    scanf("%lld", &n);
    //cin>>n;
    while (n--) {
        scanf("%lld %lld", &D, &I);
        //cin >> D >> I;
        I--; D--;
        pos = 1;
        while (D--) {
            if (I%2) pos = pos * 2 + 1;
            else pos = pos * 2;
            I >>= 1;
        }
        printf("%lld\n", pos);
        //cout << pos << '\n';
    }
}
