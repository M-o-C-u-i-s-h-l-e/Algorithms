#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int find(pair<int, int> subsets[], int i) {
  if (subsets[i].first != i)
    subsets[i].first = find(subsets, subsets[i].first);
  return subsets[i].first;
}

void Union(pair<int, int> subsets[], int x, int y) {
  int xroot = find(subsets, x);
  int yroot = find(subsets, y);
  if (subsets[xroot].second < subsets[yroot].second)
    subsets[xroot].first = yroot;
  else if (subsets[xroot].second > subsets[yroot].second)
    subsets[yroot].first = xroot;
  else {
    subsets[yroot].first = xroot;
    subsets[xroot].second++;
  }
}

int karger(int v, int e, pair<int, int> edge[]) {
  pair<int, int> subsets[v];
  for (int i = 0; i < v; i++)
    subsets[i].first = i, subsets[i].second = 0;
  int vertices = v;
  while (vertices > 2) {
    int i = rand() % e;
    int subset1 = find(subsets, edge[i].first);
    int subset2 = find(subsets, edge[i].second);
    if (subset1 == subset2) continue;
    else {
      vertices--;
      Union(subsets, subset1, subset2);
    }
  }
  int cutedges = 0;
  for (int i = 0; i < e; i++) {
    int subset1 = find(subsets, edge[i].first);
    int subset2 = find(subsets, edge[i].second);
    if (subset1 != subset2)
      cutedges++;
  }
  return cutedges;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int v, e;
  cin >> v >> e;
  pair<int, int> edge[e];
  for (int i = 0; i < e; i++)
    cin >> edge[i].first >> edge[i].second;
  srand(time(NULL));  // for initializing different seed value for every run
  cout << karger(v, e, edge) << endl;
}
