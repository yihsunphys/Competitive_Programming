#include <bits/stdc++.h>
using namespace std;
struct costomer{
  int start, end, room, idx;
};
bool cmp(costomer x, costomer y){
  return x.start < y.start; 
}
costomer a[200005];
int ans[200005];
int main() {
  int n;
  cin >> n;
  for(int i= 0; i < n; i++){
    cin >> a[i].start >> a[i].end;
    a[i].idx = i;
  }
  sort(a, a+n, cmp);
  map<int,int> mp; 
  priority_queue<pair<int, int>> pq;
  int last_room = 1;
  pq.push({-a[0].end, last_room});
  ans[a[0].idx] = 1;
  for(int i = 1; i < n; i++) {
    if(-pq.top().first < a[i].start) { 
      pq.push({-a[i].end, pq.top().second});
      ans[a[i].idx] = pq.top().second;
      pq.pop();
    }
    else{
      pq.push({-a[i].end, ++last_room});
      ans[a[i].idx] = last_room;
    }
  }
  cout << last_room << '\n';
  for(int i = 0; i < n; i++)
    cout << ans[i] << " ";
}