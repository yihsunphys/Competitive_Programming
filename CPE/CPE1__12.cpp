#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int N,P;
        cin>>N>>P;
        int p[P];
        for(int i=0; i<P; i++){
            cin>>p[i];
        }
        int sum=0;
        for(int i=1; i<=N; i++){
             int k=0;
            for(int j=0; j<P; j++){
                if(i%p[j]==0) k=1;
            }
            if(k==1&&i%7!=0&&i%7!=6) sum++;
        }
        cout<<sum<<endl;
    }
    return 0;
}
/*--------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
int a[1000];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  while(n--) {
    int day;
    cin >> day;
    int num;
    cin >> num;
    for(int i = 1; i <= num; i++)
      cin >> a[i];
    int cnt = 0;
    for(int i = 1; i <= day; i++) {
      for(int j = 1; j <= num; j++) {
        if(i%a[j] == 0 && i%7 != 0 && i%7 != 6) {
          cnt++; break;
        }
      }
    }
    cout << cnt <<'\n';
  }
}
//算餘數
