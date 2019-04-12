#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pii pair<int, int>

class Graph {
public:
  int V;
  list<int> *adj;
  vector<pair<int, pii>> edges;
  Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
  }
  void addEdge(int u, int v, int w) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    edges.push_back({w, {u, v}});
  }
  void dfs(int v, bool visited[]);
  bool isConnected();
  void reverseDeleteMST();
};

void Graph::dfs(int v, bool visited[]) {
  visited[v] = true;
  for (auto i = adj[v].begin(); i != adj[v].end(); i++)
    if (!visited[*i])
      dfs(*i, visited);
}

bool Graph::isConnected() {
  bool visited[V];
  memset(visited, false, sizeof(visited));
  dfs(0, visited);
  for (int i = 1; i < V; i++)
    if (!visited[i])
      return false;
  return true;
}

void Graph::reverseDeleteMST() {
  sort(edges.begin(), edges.end());
  int mst_wt = 0;
  for (int i = edges.size()-1; i >= 0; i--) {
    int u = edges[i].second.first;
    int v = edges[i].second.second;
    adj[u].remove(v);
    adj[v].remove(u);
    if (!isConnected()) {
      adj[u].push_back(v);
      adj[v].push_back(u);
      cout << u << " " << v << endl;
      mst_wt += edges[i].first;
    }
  }
  cout << mst_wt << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int V = 9;
  Graph g(V);
  g.addEdge(0, 1, 4);
  g.addEdge(0, 7, 8);
  g.addEdge(1, 2, 8);
  g.addEdge(1, 7, 11);
  g.addEdge(2, 3, 7);
  g.addEdge(2, 8, 2);
  g.addEdge(2, 5, 4);
  g.addEdge(3, 4, 9);
  g.addEdge(3, 5, 14);
  g.addEdge(4, 5, 10);
  g.addEdge(5, 6, 2);
  g.addEdge(6, 7, 1);
  g.addEdge(6, 8, 6);
  g.addEdge(7, 8, 7);
  g.reverseDeleteMST();
}
