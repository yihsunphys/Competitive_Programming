#include <bits/stdc++.h>
using namespace std;

// 自定義哈希函數
namespace std {
    template<>
    struct hash<pair<int, int>> {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };
}

class DSU {
private:
    vector<int> parent, size;
    vector<unordered_map<int, int>> color_count;
    int components;

public:
    DSU(int n, vector<int>& colors) : parent(n), size(n, 1), color_count(n), components(n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            color_count[i][colors[i]] = 1;
        }
    }

    // 路徑壓縮
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // 路徑壓縮
        }
        return parent[x];
    }

    // 按大小合併
    void unite(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if (root_x != root_y) {
            // 按大小合併，將較小的樹合併到較大的樹
            if (size[root_x] < size[root_y]) {
                swap(root_x, root_y);
            }
            parent[root_y] = root_x;
            size[root_x] += size[root_y];
            components--;

            // 合併顏色統計
            for (auto& [color, count] : color_count[root_y]) {
                color_count[root_x][color] += count;
            }
        }
    }

    int getSize(int x) {
        return size[find(x)];
    }

    int getDistinctColors(int x) {
        return color_count[find(x)].size();
    }

    int getComponents() {
        return components;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> colors(n);
    for (int i = 0; i < n; ++i) {
        cin >> colors[i];
    }

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
        --edges[i].first, --edges[i].second;
    }

    int q;
    cin >> q;
    vector<pair<int, pair<int, int>>> queries(q);

    // 儲存查詢
    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            queries[i] = {1, {u, v}};
        } else {
            int u;
            cin >> u;
            --u;
            queries[i] = {2, {u, -1}};
        }
    }

    // 初始化並查集
    DSU dsu(n, colors);

    // 儲存刪除的邊，使用哈希集合來加速查詢
    unordered_set<pair<int, int>> removed;
    for (int i = 0; i < q; ++i) {
        if (queries[i].first == 1) {
            int u = queries[i].second.first;
            int v = queries[i].second.second;
            if (u > v) swap(u, v);  // 確保(u, v)的順序一致
            removed.insert({u, v});
        }
    }

    // 根據查詢反向處理
    vector<tuple<int, int, int>> results;

    // 首先處理剩餘的邊，並初始化並查集
    for (int i = 0; i < m; ++i) {
        int u = edges[i].first, v = edges[i].second;
        if (u > v) swap(u, v);  // 確保(u, v)的順序一致
        if (removed.find({u, v}) == removed.end()) {
            dsu.unite(u, v);
        }
    }

    // 反向處理查詢
    for (int i = q - 1; i >= 0; --i) {
        if (queries[i].first == 1) {
            // 恢復刪除的邊
            int u = queries[i].second.first;
            int v = queries[i].second.second;
            dsu.unite(u, v);
        } else {
            // 處理查詢
            int u = queries[i].second.first;
            results.push_back({dsu.getComponents(), dsu.getSize(u), dsu.getDistinctColors(u)});
        }
    }

    // 輸出結果（因為是反向處理，所以需要反轉結果順序）
    reverse(results.begin(), results.end());
    for (auto& [components, size, distinct_colors] : results) {
        cout << components << " " << size << " " << distinct_colors << "\n";
    }

    return 0;
}
