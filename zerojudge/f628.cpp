#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    int to, w;
    node(int _to, int _w){
        to = _to;
        w = _w;
    }
};

long long n, m, u, v,  x;
vector <node> edge[100005];
bool visit[100005];
vector<long long> d(100001, LLONG_MAX);

void dijkstra() {
  priority_queue<pair<long, long>> q;
  q.push({0, 1});
  d[1] = 0;
  while(!q.empty()) {
    q.pop();
    for(auto i:edge[u]){
        if(d[i.to]> d[u] + i.w) {
            d[i.to] = d[u]+i.w;
            q.push({-d[i.to], i.to});
        }
    }
  }
}

int main() {
    scanf("%lld%lld", &n, &m);
    while(m--) {
        scanf("%lld%lld%lld", &u, &v, &x);
        edge[u].push_back(node(v, x));
    }
    dijkstra();
    long long sum = 0;
    for(ll i = 1; i <= n; i++) {
        sum += d[i];
    }
    printf("%lld", sum);
}
