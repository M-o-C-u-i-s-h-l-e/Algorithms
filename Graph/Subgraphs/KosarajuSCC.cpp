#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class Graph {
public:
  int v;
  list<int> *adj;
  Graph(int v) {
    this->v = v;
    adj = new list<int>[v];
  }
  void addEdge(int u, int v) {
    adj[u].push_back(v);
  }
  void fillOrder(int v, bool visited[], stack<int> &st);
  void DFSUtil(int v, bool visited[]);
  void printSCC();
  Graph GraphTranspose();
};

void Graph::DFSUtil(int v, bool visited[]) {
  visited[v] = true;
  cout << v << " ";
  for (auto i = adj[v].begin(); i != adj[v].end(); i++)
    if (!visited[*i])
      DFSUtil(*i, visited);
}

Graph Graph::GraphTranspose() {
  Graph g(v);
  for (int i = 0; i < v; i++) {
    for (auto itr = adj[i].begin(); itr != adj[i].end(); itr++)
      g.adj[*itr].push_back(i);
  }
  return g;
}

void Graph::fillOrder(int v, bool visited[], stack<int> &st) {
  visited[v] = true;
  for (auto i = adj[v].begin(); i != adj[v].end(); i++)
    if (!visited[*i])
      fillOrder(*i, visited, st);
  st.push(v);
}

void Graph::printSCC() {
  stack<int> st;
  bool visited[v];
  memset(visited, false, sizeof(visited));
  for (int i = 0; i < v; i++)
    if (!visited[i])
      fillOrder(i, visited, st);
  Graph gt = GraphTranspose();
  memset(visited, false, sizeof(visited));
  while (!st.empty()) {
    int V = st.top();
    st.pop();
    if (!visited[V]) {
      gt.DFSUtil(V, visited);
      cout << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  Graph g(5);
  g.addEdge(1, 0);
  g.addEdge(0, 2);
  g.addEdge(2, 1);
  g.addEdge(0, 3);
  g.addEdge(3, 4);
  g.printSCC();
}
