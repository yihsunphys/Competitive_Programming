#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define F first 
#define S second 
int main(){
  int n, k, res = 0;
  cin >> n >> k;
  vector<pii> A(n); // 儲存電影的開始時間與結束時間 (end, start)
  for(int i = 0; i < n; i++)
    cin >> A[i].S >> A[i].F; // 將開始時間存入 S，結束時間存入 F
  sort(A.begin(), A.end()); // 依結束時間排序
  multiset<int> s; // 儲存每個成員目前的空閒時間（負數表示方便使用 lower_bound）
  for(int i = 0; i < n; i++) {
    auto it = s.lower_bound(-A[i].S); // 尋找第一個空閒時間 <= 開始時間的成員
    if(it == s.end() && s.size() == k) continue; // 如果所有成員都已排滿，略過
    if(it != s.end()) s.erase(it); // 若找到合適的成員，移除該空閒時間
    s.insert(-A[i].F); // 更新該成員的空閒時間為電影的結束時間
    res++; // 成功安排一部電影
  }
  cout << res << "\n";
}
