#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pii pair<int, int>

class Edge {
public:
  int u, v, w;
  Edge(int u, int v, int w) {
    this->u = u;
    this->v = v;
    this->w = w;
  }
  bool operator <(const Edge &x) const {
    return w < x.w;
  }
};

int edmond(vector<Edge> &edge, int V, int R) {
  vector<Edge> minInEdge(V, Edge(-1, -1, INT_MAX));
  for (Edge e : edge)
    minInEdge[e.v] = min(minInEdge[e.v], e);
  minInEdge[R] = Edge(-1, R, 0);
  vector<int> group(V, 0);
  vector<bool> visited(V, false);
  vector<bool> isCycleGroup(V, false);
  int Count = 0;
  for (int i = 0; i < V; i++) {
    if (visited[i]) continue;
    int node = i;
    vector<int> path;
    while (node != -1 && !visited[node]) {
      visited[node] = true;
      path.push_back(node);
      node = minInEdge[node].u;
    }
    bool isCycle = false;
    for (int v : path) {
      group[v] = Count;
      if (v == node)  isCycleGroup[Count] = isCycle = true;
      if (!isCycle) Count++;
    }
    if (isCycle)  Count++;
  }
  int result = 0;
  if (Count == V) {
    for (Edge e : minInEdge)
      result += e.w;
    return result;
  }
  for (Edge e : minInEdge)
    if (isCycleGroup[group[e.v]])
      result += e.w;
  vector<Edge> n_edge;
  for (Edge e : edge) {
    int u = group[e.u], v = group[e.v], w = e.w;
    if (u == v) continue;
    else if (isCycleGroup[v])
      n_edge.push_back(Edge(u, v, w - minInEdge[e.v].w));
    else
      n_edge.push_back(Edge(u, v, w));
  }
  return result + edmond(n_edge, Count, group[R]);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int V, E, R;
  cin >> V >> E >> R;
  vector<Edge> edge;
  for (int i = 0, u, v, w; i < E; i++) {
    cin >> u >> v >> w;
    edge.push_back(Edge(u, v, w));
  }
  int result = edmond(edge, V, R);
  cout << result << endl;
}
