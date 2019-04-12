#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class Edge {
public:
  int v, flow, C, rev;
};

class Graph {
  int V;
  int *level;
  vector<Edge> *adj;
public:
  Graph(int V) {
    adj = new vector<Edge>[V];
    this->V = V;
    level = new int[V];
  }
  void addEdge(int u, int v, int C) {
    Edge a{v, 0, C, adj[v].size()};
    Edge b{u, 0, 0, adj[u].size()};
    adj[u].push_back(a);
    adj[v].push_back(b);
  }
  bool bfs(int s, int t);
  int sendFlow(int s, int flow, int t, int ptr[]);
  int dinci(int s, int t);
};

bool Graph::bfs(int s, int t) {
  for (int i = 0; i < V; i++)
    level[i] = -1;
  level[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
      Edge &e = *i;
      if (level[e.v] < 0 && e.flow < e.C) {
        level[e.v] = level[u] + 1;
        q.push(e.v);
      }
    }
  }
  return level[t] < 0 ? false : true;
}

int Graph::sendFlow(int u, int flow, int t, int start[]) {
  if (u == t)
    return flow;
  for ( ; start[u] < adj[u].size(); start[u]++) {
    Edge &e = adj[u][start[u]];
    if (level[e.v] == level[u]+1 && e.flow < e.C) {
      int cur_flow = min(flow, e.C - e.flow);
      int temp_flow = sendFlow(e.v, cur_flow, t, start);
      if (temp_flow > 0) {
        e.flow += temp_flow;
        adj[e.v][e.rev].flow -= temp_flow;
        return temp_flow;
      }
    }
  }
  return 0;
}

int Graph::dinci(int s, int t) {
  if (s == t)
    return -1;
  int total = 0;
  while (bfs(s, t)) {
    int *start = new int[V+1];
    while (int flow = sendFlow(s, INT_MAX, t, start))
      total += flow;
  }
  return total;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int v, e;
  cin >> v >> e;
  Graph g(v);
  for (int i = 0; i < e; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    g.addEdge(x, y, c);
  }
  int s, t;
  cin >> s >> t;
  cout << g.dinci(s, t) << endl;
}
