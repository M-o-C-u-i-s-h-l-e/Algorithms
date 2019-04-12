#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void addEdge(vector<int> adj[], int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void greedyColoring(vector<int> adj[], int V) {
  int result[V];
  result[0] = 0;
  for (int u = 1; u < V; u++) result[u] = -1;
  bool available[V];
  memset(available, false, sizeof(available));
  for (int u = 1; u < V; u++) {
    for (auto i = adj[u].begin(); i != adj[u].end(); i++)
      if (result[*i] != -1)
        available[result[*i]] = true;
    int cr;
    for (cr = 0; cr < V; cr++)
      if (!available[cr])
        break;
    result[u] = cr;
    for (auto i = adj[u].begin(); i != adj[u].end(); i++)
      if (result[*i] != -1)
        available[result[*i]] = false;
  }
  for (int u = 0; u < V; u++)
    cout << u << " " << result[u] << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int v, e;
  cin >> v >> e;
  vector<int> adj[v];
  for (int i = 0; i < e; i++) {
    int x, y;
    cin >> x >> y;
    addEdge(adj, x, y);
  }
  greedyColoring(adj, v);
}
