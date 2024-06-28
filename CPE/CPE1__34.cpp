#include <bits/stdc++.h>
using namespace std;
int count(int x, int y){
  int n = x+y;
  int sum = (1+n)*n/2;
  return sum+x+1;
}
int main(){
  int n;
  cin >> n;
  int x1, y1, x2, y2;
  int id = 1;
  while(n--){
    cout << "Case " << id <<": ";
    id++;
    cin >> x1 >> y1 >> x2 >> y2;
    int dis1 = count(x1, y1);
    int dis2 = count(x2, y2);
    cout << dis2-dis1<<'\n';
  }
}
