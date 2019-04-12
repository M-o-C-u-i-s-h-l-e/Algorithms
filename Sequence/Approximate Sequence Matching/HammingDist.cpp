// For tow strings with same length
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int hammingDist(string a, string b) {
  int i = 0, Count = 0;
  while (a[i] != '\0') {
    if (a[i] != b[i]) Count++;
    i++;
  }
  return Count;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string a, b;
  cin >> a >> b;
  cout << hammingDist(a, b) << endl;
}
