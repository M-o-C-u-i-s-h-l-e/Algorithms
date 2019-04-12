#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int OSA(string a, string b) {
  int n1 = a.length(), n2 = b.length();
  int d[n1+1][n2+1];
  for (int i = 0; i <= n1; i++)
    d[i][0] = i;
  for (int i = 0; i <= n2; i++)
    d[0][i] = i;
  for (int i = 1; i <= n1; i++)
    for (int j = 1; j <= n2; j++)
      d[i][j] = (a[i-1] == b[j-1]) ? d[i-1][j-1] : min(d[i-1][j], min(d[i][j-1], d[i-1][j-1])) + 1;
  return d[n1][n2];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string str1, str2;
  cin >> str1 >> str2;
  cout << OSA(str1, str2) << endl;
}
