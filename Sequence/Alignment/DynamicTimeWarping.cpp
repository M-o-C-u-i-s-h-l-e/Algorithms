#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int dynamicTimeWarping(string a, string b, int n, int m) {
  int dtw[n+1][m+1];
  for (int i = 1; i <= n; i++) dtw[i][0] = INT_MAX;
  for (int i = 1; i <= m; i++) dtw[0][i] = INT_MAX;
  dtw[0][0] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      dtw[i][j] = abs(a[i] - b[j]) + min(dtw[i-1][j], min(dtw[i][j-1], dtw[i-1][j-1]));
  return dtw[n][m];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string a, b;
  cin >> a >> b;
  int n = a.length(), m = b.length();
  cout << dynamicTimeWarping(a, b, n, m) << endl;
}
