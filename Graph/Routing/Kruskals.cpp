#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pii pair<int, int>

class Graph {
public:
  int V, E;
  vector<pair<int, pii>> edges;
  Graph(int V, int E) {
    this->V = V;
    this->E = E;
  }
  void addEdge(int u, int v, int w) {
    edges.push_back({w, {u, v}});
  }
  int kruskal();
};

class DisjointSets {
public:
  int *parent, *rnk;
  int n;
  DisjointSets(int n) {
    this->n = n;
    parent = new int[n+1];
    rnk = new int[n+1];
    for (int i = 0; i <= n; i++)
      rnk[i] = 0, parent[i] = i;
  }
  int find(int u) {
    if (u != parent[u])
      parent[u] = find(parent[u]);
    return parent[u];
  }
  void merge(int x, int y) {
    x = find(x), y = find(y);
    (rnk[x] > rnk[y]) ? parent[y] = x : parent[x] = y;
    if (rnk[x] == rnk[y])
      rnk[y]++;
  }
};

int Graph::kruskal() {
  int mst_wt = 0, vCount = 0;
  sort(edges.begin(), edges.end());
  DisjointSets ds(V);
  for (auto itr = edges.begin(); itr != edges.end(); itr++) {
    int u = itr->second.first;
    int v = itr->second.second;
    int set_u = ds.find(u);
    int set_v = ds.find(v);
    if (set_u != set_v) {
      vCount++;
      cout << u << "-" << v << endl;
      mst_wt += itr->first;
      ds.merge(set_u, set_v);
    }
    if (vCount == V - 1)  break;
  }
  return mst_wt;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int V, E;
  cin >> V >> E;
  Graph g(V, E);
  for (int i = 0; i < E; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    g.addEdge(x, y, w);
  }
  int mst_wt = g.kruskal();
  cout << "Total cost of MST: " << mst_wt << endl;
}
