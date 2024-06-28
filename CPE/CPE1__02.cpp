#include <bits/stdc++.h>
using namespace std;
int main(){
  int e,n,x[100],y[100],d[100];
  cin>>e>>n;
  int a,b,k;
  char c;
  int j=0;
  string s;
  while(cin>>a>>b>>c>>s){
    int flag=0;
    if(c=='E') k=401;
    if(c=='S') k=402;
    if(c=='W') k=403;
    if(c=='N')  k=400;
    for(int i=0;i<s.length();i++){
        int flag1=0;
        if(s[i]=='R') {
                k++;
                flag1=0;
        }
        if(s[i]=='L') {
                k--;
                flag1=0;

        }
        if(s[i]=='F'){
               for(int z=0;z<=100;z++){
                    if (a==x[z]){
                        if (b==y[z]){
                           if(a==0&&b==0){
                              if(k%4==2||k%4==3){
                                 flag1=1;
                              }
                           }
                           if(a==e&&b==0){
                                if(k%4==1||k%4==2){
                                   flag1=1;
                                }
                           }
                           if(a==e&&b==n){
                                if(k%4==0||k%4==1){
                                   flag1=1;
                                }
                           }
                           if(a==0&&b==n){
                                if(k%4==0||k%4==3){
                                   flag1=1;
                                }
                           }

                           if(k==d[z]){
                              flag1=1;
                           }
                        }
                    }
                }
                if(flag1!=1){
                    if(k%4==0)  {
                            b++;

                    }
                    if(k%4==1)  {
                            a++;

                    }
                    if(k%4==2)  {
                            b--;

                    }
                    if(k%4==3)  {
                            a--;

                   }
              }
        }
        if(a>e) {
            a--;
            flag++;
            break;
        }
        if(b>n) {
            b--;
            flag++;
            break;
        }
        if(a<0) {
            a=a+1;
            flag++;
            break;
        }
        if(b<0) {
            b++;
            flag++;
            break;
        }

    }
    cout<<a<<" "<<b<<" ";
    if(k%4==0)  cout<<"N";
    if(k%4==1)  cout<<"E";
    if(k%4==2)  cout<<"S";
    if(k%4==3)  cout<<"W";
    if(flag!=0) {
        cout<<" "<<"LOST";
        x[j]=a;
        y[j]=b;
        d[j]=k;
        j++;
    }
    cout<<endl;
  }
  return 0;
}
/*--------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  map<char, int> mp; map<int, char> mp2;
  mp['N'] = 0; mp['S'] = 2; mp['E'] = 1; mp['W'] = 3;
  mp2[0] = 'N'; mp2[1] = 'E'; mp2[2] = 'S' ; mp2[3] = 'W';
  int mat[55][55];
  memset(mat, 0, sizeof(mat));
  int r, c;
  cin >> r >> c;
  
  int x, y;
  char ch;
  string s;

  while(cin >> x >> y >> ch) {
    getline(cin, s);
    getline(cin, s);
    int idx = mp[ch]; 
    bool lost = false;
    for(int i = 0; i < s.size(); i++) {
      if(s[i] =='F') {
        int xtmp = x, ytmp = y;
        if(idx == 1) xtmp++;
        if(idx == 2) ytmp--;
        if(idx == 3) xtmp--;
        if(idx == 0) ytmp++;

        if(xtmp>=0 && xtmp <=r && ytmp>=0 && ytmp<=c){
          x = xtmp; y = ytmp;
        }
        else {
          if(mat[x][y] == 1) continue;
          else {
            mat[x][y] = 1;
            lost = true;
            break;
          }
        }
      }
      else if(s[i] == 'R') idx = (idx + 1)%4;
      else if(s[i] == 'L') idx = (idx + 3) % 4;

      //cout<<x<<y<< mp2[idx]<<'\n';
    }
    cout << x << " " << y << " " << mp2[idx];
    if(lost) cout<<" LOST\n";
    else cout<<'\n';
    
  }
}
//陣列不要動態指定
//分為FRL 三個case 當F時 先暫存 xtmp ytmp
