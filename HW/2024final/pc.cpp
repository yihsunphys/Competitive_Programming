#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;
const long long INF = 1e18;

struct Edge {
    int to, w;
    Edge(int to, int w) : to(to), w(w) {}
};

vector<Edge> g[MAXN];
long long dist[MAXN];
int n, m;
vector<int> a;

void dijkstra(int s) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    fill(dist, dist + n + 1, INF);
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto e : g[u]) {
            if (dist[u] + e.w < dist[e.to]) {
                dist[e.to] = dist[u] + e.w;
                pq.push({dist[e.to], e.to});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // 建立虛擬點 0
    for (int i = 1; i <= n; ++i) {
        g[0].push_back({i, a[i - 1]}); // 虛擬點 0 到點 i 的距離為 a[i-1]
        g[i].push_back({0, a[i - 1]});
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    // 從城市 1 開始執行 Dijkstra
    dijkstra(1); 

    cout << dist[n] << endl;
    return 0;
}