#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define n 4

bool wPreferM1OverM(int prefer[2*n][n], int w, int m, int m1) {
  for (int i = 0; i < n; i++) {
    if (prefer[w][i] == m1)  return true;
    if (prefer[w][i] == m)   return false;
  }
}

void stableMarriage(int prefer[2*n][n]) {
  int wPartner[n];
  bool mFree[n];
  memset(wPartner, -1, sizeof(wPartner));
  memset(mFree, false, sizeof(mFree));
  int freeCount = n;
  while (freeCount > 0) {
    int m;
    for (m = 0; m < n; m++)
      if (!mFree[m]) break;
    for (int i = 0; i < n && !mFree[m]; i++) {
      int w = prefer[m][i];
      if (wPartner[w-n] == -1) {
        wPartner[w-n] = m;
        mFree[m] = true;
        freeCount--;
      } else {
        int m1 = wPartner[w-n];
        if (!wPreferM1OverM(prefer, w, m, m1)) {
          wPartner[w-n] = m;
          mFree[m] = true;
          mFree[m1] = false;
        }
      }
    }
  }
  for (int i = 0; i < n; i++)
    cout << i + n << " " << wPartner[i] << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int prefer[2*n][n] = {
    {7, 5, 6, 4},
    {5, 4, 6, 7},
    {4, 5, 6, 7},
    {4, 5, 6, 7},
    {0, 1, 2, 3},
    {0, 1, 2, 3},
    {0, 1, 2, 3},
    {0, 1, 2, 3}
  };
  stableMarriage(prefer);
}
