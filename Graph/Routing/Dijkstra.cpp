#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pii pair<int, int>

void addEdge(vector<pii> adj[], int u, int v, int w) {
  adj[u].emplace_back(v, w);
  adj[v].emplace_back(u, w);
}

void shortestPath(vector<pii> adj[], int V, int src) {
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  vector<int> dist(V, INT_MAX);
  pq.push(make_pair(0, src));
  dist[src] = 0;
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    for (auto i : adj[u]) {
      int v = i.first;
      int weight = i.second;
      if (dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight;
        pq.push(make_pair(dist[v], v));
      }
    }
  }
  for (int i = 0; i < V; i++)
    cout << i << " " << dist[i] << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int v, e;
  cin >> v >> e;
  vector<pii> adj[v];
  for (int i = 0; i < e; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    addEdge(adj, x-1, y-1, w);
  }
  shortestPath(adj, v, 0);
}
