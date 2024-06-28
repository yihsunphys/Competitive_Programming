#include <bits/stdc++.h>
using namespace std;
int main(){
   int n,m;
   int c=0;
   int dx[]={-1,-1,-1,0,0,1,1,1};
   int dy[]={-1,1,0,1,-1,0,1,-1};
   while(cin>>n>>m){
    c++;
    if(n==0&&m==0)  break;
    cout<<"Field #"<<c<<":"<<endl;
    string s;
    char a[n][m];
    int b[n][m];
    for(int i=0;i<n;i++){
      cin>>s;
      for(int j=0;j<m;j++){
           a[i][j]=s[j];
       }
     }
     memset(b,0,sizeof(b));
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='*') b[i][j]=-1;
            else{
                for(int k=0;k<8;k++){
                        int x=i+dx[k];
                        int y=j+dy[k];
                    if(a[x][y]=='*'&&x>=0&&x<n&&y>=0&&y<m)   b[i][j]++;
                }
            }
        }
     }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              if(b[i][j]==-1) cout<<"*";
              else cout<<b[i][j];
            }
           cout<<endl;
        }
   }
   return 0;
}
/*---------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
char mat[100][100];
int dx[] = {-1, 0, 1};
int dy[] = {-1, 0, 1};
int main() {
  int r, c;
  int id = 1;
  while(cin >> r >> c) {
    if(r == 0 && c == 0) break;
    if(id!=1) cout<<'\n';
    cout << "Field #" << id << ":\n";
    id++;

    for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
        cin >> mat[i][j];
      }
    }
    for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
        if(mat[i][j] == '*') cout << '*';
        else {
          int cnt = 0;
          for(int k = 0; k < 3; k++) {
            for(int m = 0; m < 3; m++) {
              if(mat[i+dx[k]][j+dy[m]] == '*') cnt++;
            }
          }
          cout<<cnt;
        }
      }
      cout << '\n';
    }
  }
}
