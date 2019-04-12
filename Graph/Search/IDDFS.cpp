// Iterative Deepening Depth First Search
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class Graph {
public:
  int V;
  list<int> *adj;
  Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
  }
  void addEdge(int u, int v) {
    adj[u].push_back(v);
  }
  bool DLS(int src, int dest, int limit);
  bool IDDFS(int src, int dest, int max_depth);
};

bool Graph::DLS(int src, int dest, int limit) {
  if (src == dest)  return true;
  if (limit <= 0)   return false;
  for (auto i = adj[src].begin(); i != adj[src].end(); i++)
    if (DLS(*i, dest, limit-1))
      return true;
  return false;
}

bool Graph::IDDFS(int src, int dest, int max_depth) {
  for (int i = 0; i < max_depth; i++)
    if (DLS(src, dest, i))
      return true;
  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  Graph g(7);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);
  g.addEdge(1, 4);
  g.addEdge(2, 5);
  g.addEdge(2, 6);
  int dest = 6, src = 0, max_depth = 3;
  if (g.IDDFS(src, dest, max_depth))
    cout << "Destination is reachable from source\n";
  else
    cout << "Destination is not reachable from source\n";
}
