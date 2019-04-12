#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pii pair<int, int>

void print(int dist[], int n) {
  for (int i = 0; i < n; i++)
    cout << i << " " << dist[i] << endl;
}

void bellmanford(vector<pair<pii, int>> edge, int src, int V, int E) {
  int dist[V];
  for (int i = 0; i < V; i++) dist[i] = INT_MAX;
  dist[src] = 0;
  for (int i = 0; i < V-1; i++) {
    for (int j = 0; j < E; j++) {
      int u = edge[j].first.first;
      int v = edge[j].first.second;
      int w = edge[j].second;
      if (dist[v] > dist[u] + w)
        dist[v] = dist[u] + w;
    }
  }
  for (int i = 0; i < E; i++) {
    int u = edge[i].first.first;
    int v = edge[i].first.second;
    int w = edge[i].second;
    if (dist[v] > dist[u] + w) {
      cout << "Graph contains negative cycles\n";
      break;
    }
  }
  print(dist, V);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int V, E;
  cin >> V >> E;
  vector<pair<pii, int>> edge;
  for (int i = 0; i < E; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    edge.push_back({{x, y}, w});
  }
  int src;
  cin >> src;
  bellmanford(edge, src, V, E);
}
