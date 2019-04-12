#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

double DiceCoeff(string a, string b) {
  if (a.empty() || b.empty()) return 0;
  if (a == b) return 1;
  int n1 = a.length();
  int n2 = b.length();
  if (n1 < 2 || n2 < 2) return 0;
  n1 -= 1, n2 -= 1;
  double match = 0;
  int i = 0, j = 0;
  while (i < n1 && j < n2) {
    string s1 = a.substr(i, 2);
    string s2 = b.substr(j, 2);
    if (s1.compare(s2) == 0)
      match += 2;
    i++, j++;
  }
  return match / (n1 + n2);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string a, b;
  cin >> a >> b;
  cout << DiceCoeff(a, b) << endl;
}
