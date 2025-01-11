#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n;
    while(n--){
        cin>>x;
        int a[x];
        for(int i=0;i<x;i++){
            cin>>a[i];
        }
        int y=0;
        for(int i=0;i<x-1;i++){
           for(int j=0;j<x-1;j++){
              if(a[j]>a[j+1]) {
                swap(a[j],a[j+1]);
                y++;
           }
        }
      }
        cout<<"Optimal train swapping takes "<<y<<" swaps."<<endl;
    }
    return 0;
}

------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
int y;

int bubble(int a[], int x){
     y=0;
       for(int i=0;i<x-1;i++){
           for(int j=i+1;j<x;j++){
              if(a[i]>a[j]) {
                swap(a[i],a[j]);
                y++;
           }
        }
      }
   return y;
}


int main(){
    int n,x;
    cin>>n;
    while(n--){
        cin>>x;
        int a[x];
        for(int i=0;i<x;i++){
            cin>>a[i];
        }
       bubble(a,x);
      cout<<"Optimal train swapping takes "<<y<<" swaps."<<endl;
    }
    return 0;
}
/*------------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
int bubble_sort(int a[], int x){
  int cnt = 0;
  for(int i = 0; i < x-1; i++){
    for(int j = 0; j < x-1; j++)
      if(a[j+1]<a[j]) {
        swap(a[j], a[j+1]);
        cnt++;
      }
  }
  return cnt;
}
int main(){
  int n;
  cin >> n;
  while(n--){
    int x;
    cin >> x;
    int a[x];
    for(int i = 0; i < x; i++){
      cin >> a[i];
    }
    printf("Optimal train swapping takes %d swaps.\n", bubble_sort(a,x));
  }
}
//就bubble sort
