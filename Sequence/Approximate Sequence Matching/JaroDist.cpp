#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

double jaroDist(string a, string b) {
  int n1 = a.length(), n2 = b.length();
  if (n1 == 0)
    return n2 == 0 ? 1.0 : 0.0;
  int matchDist = max(n1, n2) / 2 - 1;
  bool a_match[n1], b_match[n2];
  fill(a_match, a_match + n1, false);
  fill(b_match, b_match + n2, false);
  int match = 0;
  for (int i = 0; i < n1; i++) {
    int end = min(i + matchDist + 1, n2);
    for (int k = max(0, i - matchDist); k < end; k++) {
      if (!b_match[k] && a[i] == b[k]) {
        a_match[i] = true;
        b_match[k] = true;
        match++;
        break;
      }
    }
  }
  if (match == 0) return 0.0;
  double t = 0.0;
  int k = 0;
  for (int i = 0; i < n1; i++) {
    if (a_match[i]) {
      while (!b_match[k]) k++;
      if (a[i] != b[k]) t += 0.5;
      k++;
    }
  }
  double m = match;
  return (m / n1 + m / n2 + (m - t) / m) / 3.0;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string a, b;
  cin >> a >> b;
  cout << jaroDist(a, b) << endl;
}
