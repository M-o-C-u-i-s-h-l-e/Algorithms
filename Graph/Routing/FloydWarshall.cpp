#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void print(vector<int> dist[], int v) {
  for (int i = 0; i < v; i++) {
    for (int j = 0; j < v; j++)
      cout << dist[i][j] << " ";
    cout << endl;
  }
}

void floydWarshall(vector<int> graph[], int v) {
  vector<int> dist[v];
  for (int i = 0; i < v; i++)
    for (int j = 0; j < v; j++)
      dist[i].push_back(graph[i][j]);
  for (int k = 0; k < v; k++)
    for (int i = 0; i < v; i++)
      for (int j = 0; j < v; j++)
        if (dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];
  print(dist, v);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int v;
  cin >> v;
  vector<int> graph[v];
  for (int i = 0; i < v; i++) {
    for (int j = 0; j < v; j++) {
      int a;
      cin >> a;
      graph[i].push_back(a);
    }
  }
  floydWarshall(graph, v);
}

/*
sample input
4
0 999 -2 999
4 0 3 999
999 999 0 2
999 -1 999 0
// instead of infinity, I used 999 here
*/
