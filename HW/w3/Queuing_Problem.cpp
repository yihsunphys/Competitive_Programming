#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, t, a, b;
    cin >> n >> m;

    int offset = n;  // 用於區分每個人的 head 和 tail 編號
    vector<int> next(3 * n + 1), prev(3 * n + 1);

    // 初始化每個人的 head -> person <- tail
    for (int i = 1; i <= n; i++) {
        next[offset + i] = i;  // 每個 head 直接連到自己
        prev[offset * 2 + i] = i;  // 每個 tail 連回自己
        next[i] = offset * 2 + i;  // 每個人接到自己 tail 的前面
        prev[i] = offset + i;  // 每個人接到自己 head 的後面
    }

    // 處理每個操作指令
    while (m--) {
        cin >> t >> a >> b;
        if (t == 0) {
            // 指令 0：將 a 移動到 b 的後面
            // 先把 a 從原佇列移除
            next[prev[a]] = next[a];
            prev[next[a]] = prev[a];

            // 將 a 插入到 b 的後面
            next[a] = next[b];
            prev[a] = b;
            prev[next[b]] = a;
            next[b] = a;
        } else {
            // 指令 1：將佇列 a 的所有人移動到佇列 b 的末尾
            if (next[offset + a] == offset * 2 + a) continue;  // 若 a 的佇列是空的，跳過

            // 將佇列 a 的內容接到佇列 b 的末尾
            prev[next[offset + a]] = prev[offset * 2 + b];
            next[prev[offset * 2 + a]] = offset * 2 + b;
            next[prev[offset * 2 + b]] = next[offset + a];
            prev[offset * 2 + b] = prev[offset * 2 + a];
            next[offset + a] = offset * 2 + a;
            prev[offset * 2 + a] = offset + a;
        }
    }

    // 輸出結果
    for (int i = 1; i <= n; i++) {
        cout << "#" << i << ":";
        int idx = next[offset + i];
        while (idx != offset * 2 + i) {
            cout << " " << idx;
            idx = next[idx];
        }
        cout << "\n";
    }

    return 0;
}
