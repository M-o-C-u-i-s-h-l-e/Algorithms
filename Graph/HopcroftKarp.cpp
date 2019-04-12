#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class BipGraph {
  int m, n;
  vector<int> *adj;
  int *pairU, *pairV, *dist;
public:
  BipGraph(int m, int n);
  void addEdge(int u, int v);
  bool bfs();
  bool dfs(int u);
  int hopcroftKarp();
};

BipGraph::BipGraph(int m, int n) {
  this->m = m;
  this->n = n;
  adj = new vector<int>[m + 1];
}

void BipGraph::addEdge(int u, int v) {
  adj[u].push_back(v);
}

int BipGraph::hopcroftKarp() {
  pairU = new int[m + 1];
  pairV = new int[n + 1];
  dist = new int[m + 1];
  fill_n(pairU, m+1, 0);
  fill_n(pairV, n+1, 0);
  int result = 0;
  while (bfs()) {
    for (int u = 1; u <= m; u++)
      if (pairU[u] == 0 && dfs(u))
        result++;
  }
  return result;
}

bool BipGraph::bfs() {
  queue<int> q;
  for (int u = 1; u <= m; u++) {
    if (pairU[u] == 0) {
      dist[u] = 0;
      q.push(u);
    } else {
      dist[u] = INT_MAX;
    }
  }
  dist[0] = INT_MAX;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (dist[u] < dist[0]) {
      for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
        int v = *i;
        if (dist[pairV[v]] == INT_MAX) {
          dist[pairV[v]] = dist[u] + 1;
          q.push(pairV[v]);
        }
      }
    }
  }
  return (dist[0] != INT_MAX);
}

bool BipGraph::dfs(int u) {
  if (u == 0) return true;
  for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
    int v = *i;
    if (dist[pairV[v]] == dist[u] + 1) {
      if (dfs(pairV[v])) {
        pairV[v] = u;
        pairU[u] = v;
        return true;
      }
    }
  }
  dist[u] = INT_MAX;
  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  BipGraph g(4, 4);
  g.addEdge(1, 2);
  g.addEdge(1, 3);
  g.addEdge(2, 1);
  g.addEdge(3, 2);
  g.addEdge(4, 2);
  g.addEdge(4, 4);
  cout << g.hopcroftKarp() << endl;
}
