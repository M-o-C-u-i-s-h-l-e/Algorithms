#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int LevenshteinDist(string a, string b) {
  int n1 = a.length();
  int n2 = b.length();
  if (n1 == 0)  return n2;
  if (n2 == 0)  return n1;
  int *cost = new int[n2 + 1];
  for (int i = 0; i <= n2; i++) cost[i] = i;
  int i = 0;
  for (auto itr1 = a.begin(); itr1 != a.end(); itr1++, i++) {
    cost[0] = i + 1;
    int corner = i, j = 0;
    for (auto itr2 = b.begin(); itr2 != b.end(); itr2++, j++) {
      int upper = cost[j + 1];
      if (*itr1 == *itr2)
        cost[j + 1] = corner;
      else {
        int t = (upper < corner) ? upper : corner;
        cost[j + 1] = (cost[j] < t ? cost[j] : t) + 1;
      }
      corner = upper;
    }
  }
  int result = cost[n2];
  delete[] cost;
  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string a, b;
  cin >> a >> b;
  cout << LevenshteinDist(a, b) << endl;
}
