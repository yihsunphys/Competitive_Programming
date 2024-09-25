#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

const int MAXN = 1000006;

vector<int> parent(MAXN);          // 並查集的根
vector<list<int>> queues(MAXN);    // 每個隊列存儲人員
unordered_map<int, int> pos;       // 每個人的位置，記錄他屬於哪個隊列

// 查詢一個人的根隊列
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

// 合併兩個隊列
void unionQueue(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA != rootB) {
        // 將隊列 rootA 合併到 rootB
        if (!queues[rootA].empty()) {
            queues[rootB].splice(queues[rootB].end(), queues[rootA]);
        }
        parent[rootA] = rootB;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    // 初始化每個人的隊列和並查集
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        queues[i].push_back(i);  // 每個人初始在自己的隊列
        pos[i] = i;  // 每個人的位置在自己隊列
    }
    
    // 處理每個指令
    for (int i = 0; i < m; ++i) {
        int t, a, b;
        cin >> t >> a >> b;
        
        if (t == 0) {
            // 將 a 移動到 b 的後面
            int rootA = find(a);
            int rootB = find(b);
            if (rootA != rootB) {
                // 將 a 移出當前隊列並加到 b 所在的隊列
                queues[rootA].remove(a);  // 移除 a 從它當前所在隊列
                queues[rootB].push_back(a);  // 將 a 加到 b 的隊列末尾
                pos[a] = rootB;  // 更新 a 的位置
            }
        } else if (t == 1) {
            // 合併隊列 a 到隊列 b
            unionQueue(a, b);
        }
    }
    
    // 輸出結果
    for (int i = 1; i <= n; ++i) {
      cout << "#" << i << ":";
        if (find(i) == i) {  // 輸出隊列的根   
            for (int person : queues[i]) {
                cout << " " << person;
            }   
        }
      cout << "\n";
    }

    return 0;
}
