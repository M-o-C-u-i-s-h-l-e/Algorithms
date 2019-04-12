#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void BFS(vector<int> adj[], int s, int v) {
  bool visited[v];
  memset(visited, false, sizeof(visited));
  queue<int> q;
  q.push(s);
  visited[s] = true;
  while (!q.empty()) {
    s = q.front();
    q.pop();
    cout << s << " ";
    for (auto i = adj[s].begin(); i != adj[s].end(); i++) {
      if (!visited[*i]) {
        visited[*i] = true;
        q.push(*i);
      }
    }
  }
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
  BFS(adj, s, v);
}
