#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class Graph {
public:
  int V;
  bool **tc;
  list<int> *adj;
  Graph(int V) {
    this->V = V;
    this->adj = new list<int>[V];
    tc = new bool*[V];
    for (int i = 0; i < V; i++) {
      tc[i] = new bool[V];
      memset(tc[i], false, sizeof(tc[i]));
    }
  }
  void addEdge(int u, int v) {
    adj[u].push_back(v);
  }
  void dfs(int u, int v);
  void transitiveClosure();
};

void Graph::dfs(int u, int v) {
  tc[u][v] = true;
  for (auto i = adj[v].begin(); i != adj[v].end(); i++)
    if (!tc[u][*i])
      dfs(u, *i);
}

void Graph::transitiveClosure() {
  for (int i = 0; i < V; i++)
    dfs(i, i);
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++)
      cout << tc[i][j] << " ";
    cout << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);
  g.transitiveClosure();
}
