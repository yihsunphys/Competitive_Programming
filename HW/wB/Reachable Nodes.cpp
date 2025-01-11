#include <bits/stdc++.h>
#define N 50001
using namespace std;
int main(){
    int n, m, a, b;
    cin >> n >> m;
    vector<bitset<N>> dp(n);  // 每個節點的可達節點集合
    vector<int> in(n), q;     // 入度與拓撲排序隊列
    vector<vector<int>> G(n); // 鄰接表存圖

    // 建圖與記錄入度
    while (m--) {
        cin >> a >> b;
        G[b - 1].push_back(a - 1); // 注意圖的方向：b -> a
        in[a - 1]++;              // 增加 a 節點的入度
    }

    // 初始化 dp 和入度為 0 的節點
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1; // 自己可以到達自己
        if (in[i] == 0) q.push_back(i);
    }
    for (int i = 0; i < n; i++) {
      int now = q[i];  // 目前處理的節點
      for (auto j : G[now]) {
        dp[j] |= dp[now];   // 合併 now 的可達集合到 j
        if (--in[j] == 0)   // 若 j 的入度減少到 0，加入隊列
            q.push_back(j);
      }
    }
    for (int i = 0; i < n; i++)
      cout << dp[i].count() << " \n"[i == n - 1]; // 計算可達節點數
}

