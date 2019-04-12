#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int **graph;

int minKey(int v, int key[], bool mstSet[]) {
  int min = INT_MAX, min_index;
  for (int i = 0; i < v; i++)
    if (!mstSet[i] && key[i] < min)
      min = key[i], min_index = i;
  return min_index;
}

void print(int parent[], int v) {
  for (int i = 1; i < v; i++)
    cout << parent[i] << "-" << i << " " << graph[i][parent[i]] << endl;
}

void prim(int V) {
  int parent[V], key[V];
  bool mstSet[V];
  for (int i = 0; i < V; i++) key[i] = INT_MAX;
  memset(mstSet, false, sizeof(mstSet));
  key[0] = 0;
  parent[0] = -1;
  for (int i = 0; i < V-1; i++) {
    int u = minKey(V, key, mstSet);
    mstSet[u] = true;
    for (int v = 0; v < V; v++)
      if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
        parent[v] = u, key[v] = graph[u][v];
  }
  print(parent, V);
}

int main(void) {
  int v;
  cin >> v;
  graph = new int*[v];
  for (int i = 0; i < v; i++) {
    graph[i] = new int[v];
    for (int j = 0; j < v; j++)
      cin >> graph[i][j];
  }
  prim(v);
}

/*
sample input
5
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0
*/
