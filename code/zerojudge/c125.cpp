#include <bits/stdc++.h>
using namespace std;
/*----------------------------------*/
vector<pair<int, int> > v;
int main(){
    int n;
    int cnt = 0;
    int d[205][205];
    while(cin >> n){
      cnt++;
      if(n == 0) break;
      pair<int, int> p;
      v.clear();
      for(int i = 0; i < n; i++){
          cin >> p.first >> p.second;
          v.push_back(p); 
      }
      int temp;
      for(int i = 0; i < n-1; i++){
          for(int j = i; j < n; j++){
              temp = pow(v[i].first-v[j].first, 2) + pow(v[i].second-v[j].second, 2);
              d[i][j]=temp;
              d[j][i]=temp;
          }
      }

      for(int k=0; k<n; k++) //嘗試每一個中繼點
        for(int i=0; i<n; i++) //計算每個i到j
          for(int j=0; j<n; j++)
            d[i][j]=min(d[i][j], max(d[i][k], d[k][j]));
      float ans = d[0][1];
      //cout<<"Scenario #"<<cnt<<"\nFrog Distance = "<<fixed<<setprecision(3)<<sqrt(ans)<<endl;
      printf("Scenario #%d\nFrog Distance = %.3f\n", cnt, sqrt(ans));
    }
}
