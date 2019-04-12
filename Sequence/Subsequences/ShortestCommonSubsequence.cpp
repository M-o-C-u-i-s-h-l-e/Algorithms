#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

string print(string s1, string s2) {
  int n = s1.length(), m = s2.length();
  int arr[n+1][m+1];
  for (int i = 0; i <= n; i++)  arr[i][0] = i;
  for (int i = 0; i <= m; i++)  arr[0][i] = i;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      arr[i][j] = (s1[i-1] == s2[j-1]) ? arr[i-1][j-1] + 1 : min(arr[i-1][j], arr[i][j-1]) + 1;
  int i = n, j = m;
  string str = "";
  while (i > 0 && j > 0) {
    if (s1[i-1] == s2[j-1]) {
      str += s1[i-1];
      i--, j--;
    } else if (arr[i-1][j] > arr[i][j-1]) {
      str += s2[j-1];
      j--;
    } else {
      str += s1[i-1];
      i--;
    }
  }
  while (i > 0) {
    str += s1[i-1];
    i--;
  }
  while (j > 0) {
    str += s2[j-1];
    j--;
  }
  reverse(str.begin(), str.end());
  return str;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string s1, s2;
  cin >> s1 >> s2;
  string str = print(s1, s2);
  cout << str << endl << str.length() << endl;
}
