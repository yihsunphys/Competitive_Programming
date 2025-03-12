#include <bits/stdc++.h>
using namespace std;

struct State {
    vector<int> jugs; // 每個水壺的水量
    int steps;        // 已執行的步驟數
    State(vector<int> j, int s) : jugs(j), steps(s) {}
};

int main() {
    int N, Q;
    cin >> N; 
    vector<int> capacity(N);
    for (int i = 0; i < N; ++i) {
        cin >> capacity[i];
    }
    cin >> Q; 

    // 使用 BFS 探索所有可能的狀態
    queue<State> q;
    set<vector<int>> visited; 
    // 初始化狀態
    vector<int> initial(N, 0); 
    q.push(State(initial, 0));
    visited.insert(initial);

    while (!q.empty()) {
        State cur = q.front();
        q.pop();
        // 檢查是否有任一水壺的水量達到 Q
        for (int i = 0; i < N; ++i) {
            if (cur.jugs[i] == Q) {
                cout << cur.steps << endl; // 輸出最少的步驟數
                return 0;
            }
        }
        // 嘗試三種操作：裝滿水、倒空水、轉移水
        for (int i = 0; i < N; ++i) {
            // 1. 將水壺 i 裝滿
            vector<int> next = cur.jugs;
            next[i] = capacity[i];
            if (!visited.count(next)) {
                q.push(State(next, cur.steps + 1));
                visited.insert(next);
            }
            // 2. 將水壺 i 倒空
            next = cur.jugs;
            next[i] = 0;
            if (!visited.count(next)) {
                q.push(State(next, cur.steps + 1));
                visited.insert(next);
            }
            // 3. 將水從水壺 i 轉移到水壺 j
            for (int j = 0; j < N; ++j) {
                if (i == j) continue; 
                next = cur.jugs;
                int transfer = min(cur.jugs[i], capacity[j] - cur.jugs[j]);
                next[i] -= transfer;
                next[j] += transfer;
                if (!visited.count(next)) {
                    q.push(State(next, cur.steps + 1));
                    visited.insert(next);
                }
            }
        }
    }
    // 如果無法達到目標水量 Q，輸出 -1
    cout << -1 << endl;
    return 0;
}
