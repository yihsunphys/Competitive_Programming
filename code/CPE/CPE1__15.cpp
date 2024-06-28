#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  while(cin>>n){
        int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a,a+n);
  int A,b,c;
    if(n%2==0){
         A=a[n/2-1];
         b=0;
         c=0;
        for(int i=0;i<n;i++){
            if(a[i]==a[n/2-1]||a[i]==a[n/2]) b++;
        }
        if(a[n/2-1]!=a[n/2]) {
                c=a[n/2]-a[n/2-1]+1;
        }
        else c=1;
     }
    if(n%2!=0){
        A=a[(n-1)/2];
        b=0;
        for(int i=0;i<n;i++){
            if(a[i]==a[n/2-1]) b++;
        }
        c=1;
    }
    cout<<A<<" "<<b<<" "<<c<<endl;
  }
  return 0;
}
/*------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  while(cin >> n){
  for(int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);
  if(n%2 == 0) { //有兩個中位數
    int mid1 = a[n/2-1];
    int mid2 = a[n/2];
    cout << mid1 << " ";
    int cnt = 0;
    for(int i = 0; i < n; i++) 
      if(a[i] == mid1 || a[i] == mid2)
        cnt++;
    cout << cnt;
    cout << " " << mid2 - mid1 + 1 << '\n'; 
  }
  else {
    
    int mid = a[n/2];
    cout << mid << " ";
    int cnt = 0;
    for(int i = 0; i < n; i++) {
      if(a[i] == mid) cnt++;
    }
    cout << cnt;
    cout << " 1\n";  
  }
  }
}
//分兩個case來處理 只有一個中位數 跟有兩個中位數
