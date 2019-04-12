#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define V 4

void print(int reach[V][V]) {
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++)
      cout << reach[i][j] << " ";
    cout << endl;
  }
}

void transitiveClosure(int graph[V][V]) {
  int reach[V][V], i, j, k;
  for (i = 0; i < V; i++)
    for (j = 0; j < V; j++)
      reach[i][j] = graph[i][j];
  for (k = 0; k < V; k++)
    for (i = 0; i < V; i++)
      for (j = 0; j < V; j++)
        reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
  print(reach);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int graph[V][V] = {
    {1, 1, 0, 1},
    {0, 1, 1, 0},
    {0, 0, 1, 1},
    {0, 0, 0, 1}
  };
  transitiveClosure(graph);
}
