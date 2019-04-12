#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define RANGE 255

void countSort(string str) {
  char output[str.length()];
  int count[RANGE + 1], i;
  memset(count, 0, sizeof(count));
  for (i = 0; str[i]; i++)
    count[str[i]]++;
  for (i = 1; i <= RANGE; i++)
    count[i] += count[i-1];
  for (i = 0; str[i]; i++) {
    output[count[str[i]] - 1] = str[i];
    count[str[i]]--;
  }
  for (i = 0; str[i]; i++)
    str[i] = output[i];
  cout << str << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string str;
  cin >> str;
  countSort(str);
}
