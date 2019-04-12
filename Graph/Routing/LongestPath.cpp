#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class Node {
public:
  int v, w;
  Node(int v, int w) {
    this->v = v;
    this->w = w;
  }
};

class Graph {
public:
  int V;
  vector<Node> *adj;
  Graph(int V) {
    this->V = V;
    adj = new vector<Node>[V];
  }
  void addEdge(int u, int v, int w) {
    Node node(v, w);
    adj[u].push_back(node);
  }
  void topologicalSort(int v, bool visited[], stack<int> &st);
  void longestPath(int s);
};

void Graph::topologicalSort(int v, bool visited[], stack<int> &st) {
  visited[v] = true;
  for (auto i = adj[v].begin(); i != adj[v].end(); i++)
    if (!visited[(*i).v])
      topologicalSort((*i).v, visited, st);
  st.push(v);
}

void Graph::longestPath(int s) {
  stack<int> st;
  int dist[V];
  bool visited[V];
  memset(visited, false, sizeof(visited));
  for (int i = 0; i < V; i++) dist[i] = INT_MIN;
  dist[s] = 0;
  for (int i = 0; i < V; i++)
    if (!visited[i])
      topologicalSort(i, visited, st);
  while (!st.empty()) {
    int u = st.top();
    st.pop();
    if (dist[u] != INT_MIN)
      for (auto i = adj[u].begin(); i != adj[u].end(); i++)
        if (dist[(*i).v] < dist[u] + (*i).w)
          dist[(*i).v] = dist[u] + (*i).w;
  }
  for (int i = 0; i < V; i++)
    (dist[i] == INT_MIN) ? cout << "INF " : cout << dist[i] << " ";
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  Graph g(6);
  g.addEdge(0, 1, 5);
  g.addEdge(0, 2, 3);
  g.addEdge(1, 3, 6);
  g.addEdge(1, 2, 2);
  g.addEdge(2, 4, 4);
  g.addEdge(2, 5, 2);
  g.addEdge(2, 3, 7);
  g.addEdge(3, 5, 1);
  g.addEdge(3, 4, -1);
  g.addEdge(4, 5, -2);
  int s = 1;
  g.longestPath(s);
}
