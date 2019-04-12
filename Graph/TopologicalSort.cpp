#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void topologicalSortUtil(vector<int> adj[], int v, bool visited[], stack<int> &s) {
  visited[v] = true;
  for (auto i = adj[v].begin(); i != adj[v].end(); i++)
    if (!visited[*i])
      topologicalSortUtil(adj, *i, visited, s);
  s.push(v);
}

void topologicalSort(vector<int> adj[], int V) {
  stack<int> s;
  bool *visited = new bool[V];
  memset(visited, false, sizeof(visited));
  for (int i = 0; i < V; i++)
    if (!visited[i])
      topologicalSortUtil(adj, i, visited, s);
  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int V, E;
  cin >> V >> E;
  vector<int> adj[V];
  for (int i = 0; i < E; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  topologicalSort(adj, V);
}
