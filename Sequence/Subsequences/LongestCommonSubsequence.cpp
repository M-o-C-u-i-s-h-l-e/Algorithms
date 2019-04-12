#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int LCS(string s1, string s2) {
  int n = s1.length(), m = s2.length();
  int arr[n+1][m+1];
  for (int i = 0; i <= n; i++)  arr[i][0] = 0;
  for (int i = 0; i <= m; i++)  arr[0][i] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      arr[i][j] = (s1[i] == s2[j]) ? arr[i-1][j-1]+1 : max(arr[i-1][j], arr[i][j-1]);
  return arr[n][m];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string s1, s2;
  cin >> s1 >> s2;
  cout << LCS(s1, s2) << endl;
}
