#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define ll long long 
#define endl '\n'
/*----------------------------------------*/
bool v[4][100];
int a[100];
int mat[10][10];
int cnt;int row,col;
void print(){
   if(cnt==1){
      cout<<"SOLN       COLUMN"<<endl;
      cout<<"#      1 2 3 4 5 6 7 8"<<endl;
      cout<<endl;
   }
   cout<<cnt<<"     ";
   for(int i=1;i<=8;i++){
      cout<<" "<<a[i];
   }
   cout<<endl;
}

void queen(int n){
   if(n==9&&a[col]==row){
      cnt++;
      print();
      return;
   } 
   /*if(v[1][n]) {
      queen(n+1);
      return;
   }*/
   
   for(int i=1;i<=8;i++){
      if(!v[0][i]&&!v[2][n+i]&&!v[3][n-i+8]){
         v[0][i]=v[2][n+i]=v[3][n-i+8]=1;
         a[n]=i; 
         queen(n+1);
         v[0][i]=v[2][n+i]=v[3][n-i+8]=0;
      }
    }
}


int main(){
   int n;
   cin>>n;
   while(n--){
      cnt=0;
      memset(v,0,sizeof(v));
      memset(a,0,sizeof(a));
      
      cin>>row>>col;
      //a[col]=row; 
      //v[0][row]=v[1][col]=v[2][row+col]=v[3][row-col+8]=1;
      queen(1);
      cout<<endl;
   }
}
/*-----------------------------------------------------------------------------------------------*/
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define ll long long 
#define endl '\n'
/*----------------------------------------*/
bool v[4][100];
int a[100];
int mat[10][10];
int cnt;
void print(){
   if(cnt==1){
      cout<<"SOLN       COLUMN"<<endl;
      cout<<"#      1 2 3 4 5 6 7 8"<<endl;
      cout<<endl;
   }
   cout<<cnt<<"     ";
   for(int i=1;i<=8;i++){
      cout<<" "<<a[i];
   }
   cout<<endl;
}
void queen(int n){
   if(n==9){
      cnt++;
      print();
   } 
   else{
      if(v[1][n]) {
         queen(n+1);
      }
      else{
         for(int i=1;i<=8;i++){
            if(!v[0][i]&&!v[2][n+i]&&!v[3][n-i+8]){
               v[0][i]=v[2][n+i]=v[3][n-i+8]=1;
               a[n]=i; 
               queen(n+1);
               v[0][i]=v[2][n+i]=v[3][n-i+8]=0;
            }
         }
      }
   }
}
int main(){
   int n;
   cin>>n;
   while(n--){
      cnt=0;
      memset(v,0,sizeof(v));
      memset(a,0,sizeof(a));
      int row,col;
      cin>>row>>col;
      a[col]=row; 
      v[0][row]=v[1][col]=v[2][row+col]=v[3][col-row+8]=1;
      queen(1);
      cout<<endl;
   }
}

/*----------------------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;

int mat[100];
bool v[3][100];
int cnt = 0;
void print() {
  cout << cnt <<"      ";
  for(int i = 0 ; i < 8; i++)
    cout << mat[i]+1 << " \n"[i==7];
}

void queen(int idx) {
  if(idx == 8) {
    cnt++; 
    print();
    return;
  }
    if(mat[idx] != -1) queen(idx+1);
    else {
      for(int i = 0; i < 8; i++) {
        if(!v[0][i] && !v[1][idx+i] && !v[2][idx-i+8]) {
          v[0][i] = v[1][idx+i] = v[2][idx-i+8] = 1;
          mat[idx] = i;
          queen(idx+1);
          mat[idx] = -1;
          v[0][i] = v[1][idx+i] = v[2][idx-i+8] = 0;
        }
      }
    }
  }

int main() {
  int n;
    cin >> n;
    int row, col;
    while(n--) {
      cnt = 0;
      cout << "SOLN       COLUMN\n";
      cout << "#      1 2 3 4 5 6 7 8\n\n";
      memset(mat, -1, sizeof(mat));
      memset(v, 0, sizeof(v));
      cin >> row >> col;
      row--; col--;
      v[0][row] = v[1][row+col] = v[2][col-row+8] = 1;
      mat[col] = row;
      queen(0);
    } 
}
