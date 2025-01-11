#include <bits/stdc++.h>
using namespace std;    
int power[10];
int x[10];
int move(int grid, int i, int j){ //i, j 交換
    int a = (grid % power[i+1]) / power[i];
    int b = (grid % power[j+1]) / power[j];
    return grid - a * power[i] - b * power[j] + b * power[i] + a * power[j];
}
int solve(int initial_grid, int target){
  queue<pair<int, int>> q;
  q.push({initial_grid, 0});
  vector<bool> vis(power[9], false);
  while(!q.empty()){
    pair<int, int> front = q.front();
    int g = front.first;
    int dist = front.second;
    q.pop();
    if(g == target)
      return dist;
    //左右移動
    for(int i = 0; i < 8; i++) {
      if(i%3 == 2) continue;
      int swapped = move(g, 8-i, 8-(i+1));
      if(!vis[swapped]){
        q.push({swapped, dist+1});
        vis[swapped] = true;
      }
    }
    //上下移動
    for(int i = 0; i < 6; i++) {
      int swapped = move(g, 8-i, 8-(i+3));
      if(!vis[swapped]){
        q.push({swapped, dist+1});
        vis[swapped] = true;
      }
    }
  }
  return -1;
}
int main(){
  power[0] = 1;
  for(int i = 0; i <= 9; i++)
    power[i] = 9*power[i-1];
  int target = 0;
  for(int i = 0; i < 9; i++)
    target += (8-i) * power[i];
  int grid = 0;
  for(int i = 0; i < 9; i++) cin >> x[i];
  for(int i = 0; i < 9; i++){
    grid += (x[8-i]-1) * power[i];
  }
  cout << solve(grid, target) << '\n'; 
}