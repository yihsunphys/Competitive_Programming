#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  priority_queue<int> L;
  priority_queue<int, vector<int>, greater<int>> R;
  int q = -1;
  int f = -1;

  for(int i = 0; i < n; i++){
    int num;
    cin >> num;
    if(q == -1) q = num;
    else{
      if(num<q){
        //if(3*(L.size()+1)<R.size()){
        if((L.size()+R.size()+2)/4>L.size()){
          L.push(num);
        }
        else {
          L.push(num);
          R.push(q);
          q = L.top(); L.pop();
        }
      } 
      else{
        //if(3*L.size()<(R.size()+1)&&i>2){
        if((L.size()+R.size()+2)/4>L.size()){
          R.push(num);
          L.push(q);
          q = R.top(); R.pop();
        }
        else {
          R.push(num);
        }
      }    
    }
    cout << q << '\n';
  }
}