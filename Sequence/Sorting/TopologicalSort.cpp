#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class Graph {
public:
  int v;
  list<int> *adj;
  Graph(int v) {
    this->v = v;
    this->adj = new list<int>[v];
  }
  void addEdge(int u, int v) {
    adj[u].push_back(v);
  }
  void topologicalSort();
  void topologicalSortUtil(int v, bool visited[], stack<int> &st);
};

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &st) {
  visited[v] = true;
  for (auto i = adj[v].begin(); i != adj[v].end(); i++)
    if (!visited[*i])
      topologicalSortUtil(*i, visited, st);
  st.push(v);
}

void Graph::topologicalSort() {
  stack<int> st;
  bool visited[v];
  memset(visited, false, sizeof(visited));
  for (int i = 0; i < v; i++)
    if (!visited[i])
      topologicalSortUtil(i, visited, st);
  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  Graph g(6);
  g.addEdge(5, 2);
  g.addEdge(5, 0);
  g.addEdge(4, 0);
  g.addEdge(4, 1);
  g.addEdge(2, 3);
  g.addEdge(3, 1);
  g.topologicalSort();
}
