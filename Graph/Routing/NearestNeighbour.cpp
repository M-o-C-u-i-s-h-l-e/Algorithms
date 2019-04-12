#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pii pair<int, int>

int minValue(vector<pii> v, bool visited[]) {
  for (int i = 0; i < v.size(); i++)
    if (!visited[v[i].second])
      return i;
  return -1;
}

int NearestNeighbour(vector<vector<pii>> grid, int V, int src) {
  bool visited[V];
  memset(visited, false, sizeof(visited));
  int Cost = 0, j, start = src;
  visited[src] = true;
  for (int i = 0; i < V-1; i++) {
    j = minValue(grid[start], visited);
    cout << start << "," << grid[start][j].second << "  ";
    visited[grid[start][j].second] = true;
    Cost += grid[start][j].first;
    start = grid[start][j].second;
  }
  for (int i = 0; i < V; i++) {
    if (grid[start][i].second == src) {
      cout << start << "," << grid[start][i].second << endl;
      Cost += grid[start][i].first;
      break;
    }
  }
  return Cost;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int V;
  cin >> V;
  vector<vector<pii>> grid;
  for (int i = 0; i < V; i++) {
    vector<pii> v(V);
    for (int j = 0; j < V; j++) {
      cin >> v[j].first;
      v[j].second = j;
      if (i == j) v[j].first = INT_MAX;
    }
    grid.push_back(v);
  }
  for (int i = 0; i < V; i++)
    sort(grid[i].begin(), grid[i].end());
  cout << NearestNeighbour(grid, V, 0) << endl;
}
