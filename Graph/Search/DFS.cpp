#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void DFSUtil(vector<int> adj[], int v, bool visited[]) {
  visited[v] = true;
  cout << v << " ";
  for (auto i = adj[v].begin(); i != adj[v].end(); i++)
    if (!visited[*i])
      DFSUtil(adj, *i, visited);
}

void DFS(vector<int> adj[], int s, int v) {
  bool visited[v];
  memset(visited, false, sizeof(visited));
  DFSUtil(adj, s, visited);
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int v, e;
  cin >> v >> e;
  vector<int> adj[v];
  for (int i = 0; i < e; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
  }
  int s;
  cin >> s;
  DFS(adj, s, v);
}
