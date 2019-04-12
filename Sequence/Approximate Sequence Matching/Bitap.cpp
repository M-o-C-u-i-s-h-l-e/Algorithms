#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int bitapSearch(string text, string pattern) {
  int m = pattern.length();
  long pattern_mask[256];
  long R = ~1;
  if (m == 0) return -1;
  if (m > 63) {
    cout << "Pattern is too long\n";
    return -1;
  }
  for (int i = 0; i <= 255; i++)
    pattern_mask[i] = ~0;
  for (int i = 0; i < m; i++)
    pattern_mask[pattern[i]] &= ~(1L << i);
  for (int i = 0; i < text.length(); i++) {
    R |= pattern_mask[text[i]];
    R <<= 1;
    if ((R & (1L << m)) == 0)
      return i - m + 1;
  }
  return -1;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string text, pattern;
  cin >> text >> pattern;
  int pos = bitapSearch(text, pattern);
  (pos == -1) ? cout << "No match\n" : cout << "Pattern found at position " << pos << endl;
}
