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
  void SCCUtil(int u, int disc[], int low[], stack<int> *st, bool stackMember[]);
  void SCC();
};

void Graph::SCCUtil(int u, int disc[], int low[], stack<int> *st, bool stackMember[]) {
  static int time = 0;
  disc[u] = low[u] = ++time;
  st->push(u);
  stackMember[u] = true;
  for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
    int v = *i;
    if (disc[v] == -1) {
      SCCUtil(v, disc, low, st, stackMember);
      low[u] = min(low[u], low[v]);
    } else if (stackMember[v] == true) {
      low[u] = min(low[u], low[v]);
    }
  }
  int w = 0;
  if (low[u] == disc[u]) {
    while (st->top() != u) {
      w = st->top();
      cout << w << " ";
      stackMember[w] = true;
      st->pop();
    }
    w = st->top();
    cout << w << endl;
    stackMember[w] = false;
    st->pop();
  }
}

void Graph::SCC() {
  int *disc = new int[V];
  int *low = new int[V];
  bool *stackMember = new bool[V];
  stack<int> *st = new stack<int>();
  for (int i = 0; i < V; i++) {
    disc[i] = -1;
    low[i] = -1;
    stackMember[i] = false;
  }
  for (int i = 0; i < V; i++)
    if (disc[i] == -1)
      SCCUtil(i, disc, low, st, stackMember);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  /*Graph g(5);
  g.addEdge(1, 0);
  g.addEdge(0, 2);
  g.addEdge(2, 1);
  g.addEdge(0, 3);
  g.addEdge(3, 4);
  g.SCC();*/

  Graph g(11);
  g.addEdge(0, 1);
  g.addEdge(0, 3);
  g.addEdge(1, 2);
  g.addEdge(1, 4);
  g.addEdge(2, 0);
  g.addEdge(2, 6);
  g.addEdge(3, 2);
  g.addEdge(4, 5);
  g.addEdge(4, 6);
  g.addEdge(5, 6);
  g.addEdge(5, 7);
  g.addEdge(5, 8);
  g.addEdge(5, 9);
  g.addEdge(6, 4);
  g.addEdge(7, 9);
  g.addEdge(8, 9);
  g.addEdge(9, 8);
  g.SCC();
}
