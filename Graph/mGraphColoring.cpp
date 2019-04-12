#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define V 4

void print(int color[]) {
  for (int i = 0; i < V; i++)
    cout << color[i] << " ";
  cout << endl;
}

bool isSafe(int v, bool graph[V][V], int color[], int c) {
  for (int i = 0; i < V; i++)
    if (graph[v][i] && c == color[i])
      return false;
  return true;
}

bool graphColoringUtil(bool graph[V][V], int m, int color[], int v) {
  if (v == V) return true;
  for (int c = 1; c <= m; c++) {
    if (isSafe(v, graph, color, c)) {
      color[v] = c;
      if (graphColoringUtil(graph, m, color, v+1))
        return true;
      color[v] = 0;
    }
  }
  return false;
}

void graphColoring(bool graph[V][V], int m) {
  int *color = new int[V]();
  if (!graphColoringUtil(graph, m, color, 0)) {
    cout << "Solution doesn't exits\n";
    return;
  }
  print(color);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  bool graph[V][V] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
  };
  int m = 3;
  graphColoring(graph, m);
}
