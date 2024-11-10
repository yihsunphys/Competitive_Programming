#include <bits/stdc++.h>
using namespace std;
// int mat[6][6];	
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool check(int x, int y){
  return x >= 0 && x < 6 && y >= 0 && y < 6;
}
int main(){
  vector<vector<int>> mat(6, vector<int>(6));
  for(int i = 0; i < 6; i++)
    for(int j = 0; j < 6; j++)
	  cin >> mat[i][j];	
  queue<pair<vector<vector<int>>, int>> q;
  set<vector<vector<int>>> st;
  q.push({mat, 0});
  st.insert(mat);
  int mov = 0;
  while(!q.empty()){
	vector<vector<int>> cur(6, vector<int>(6));
	mov = q.front().second;
	for(int i = 0; i < 6; i++)
	  for(int j = 0; j < 6; j++)
		cur[i][j] = q.front().first[i][j];
	q.pop();
	//終止條件
	if(cur[2][5] == 1){
	  int cnt = 1;
	  for(int i = 4; i >= 0; i--){ //算1號車長度
		if(cur[2][i] != 1) break;
		cnt++;
	  }
	  mov += cnt;
	  break;
	}
	if(mov > 10) break;
	//檢查每個空格子四周是否有可以移動的車
	for(int i = 0; i < 6; i++){
	  for(int j = 0; j < 6; j++){
		if(cur[i][j] == 0){
		  for(int k = 0; k < 4; k++){
		    int x = i + dx[k], y = j + dy[k];
			if(!check(x, y) || cur[x][y] == 0) continue;
			int xx = x + dx[k], yy = y + dy[k];
			if(!check(xx, yy) || cur[x][y] != cur[xx][yy]) continue;
			while(check(xx, yy) && cur[x][y] == cur[xx][yy]){
			  xx += dx[k];
			  yy += dy[k];
			}
			xx -= dx[k], yy -= dy[k];
			swap(cur[i][j], cur[xx][yy]);
			if(!st.count(cur)){ 
			  q.push({cur, mov+1});
			  st.insert(cur);
			}
			swap(cur[i][j], cur[xx][yy]);
		  }	
		}
	  }
	}
  }
  if(mov > 10) cout << "-1\n";
  else cout << mov << '\n';
}