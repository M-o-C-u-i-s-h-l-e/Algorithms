#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void Union(int a1[], int a2[], int n, int m) {
  int i = 0, j = 0;
  while (i < n && j < m) {
    if (a1[i] < a2[j])
      cout << a1[i++] << " ";
    else if (a2[j] < a1[i])
      cout << a2[j++] << " ";
    else {
      cout << a1[i++] << " ";
      j++;
    }
  }
  while (i < n)
    cout << a1[i++] << " ";
  while (j < m)
    cout << a2[j++] << " ";
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;
  int a1[n], a2[m];
  for (int i = 0; i < n; i++) cin >> a1[i];
  for (int i = 0; i < m; i++) cin >> a2[i];
  Union(a1, a2, n, m);
}
