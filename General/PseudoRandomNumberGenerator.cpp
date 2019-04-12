#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  srand(time(NULL));  // used for making the initial seed value of random number generator to be random at each time it gets executed
  // if the above line isn't added then every time it has the same seed value as a seed value
  for (int i = 0; i < 5; i++)
    cout << rand() % 10 << " ";
  cout << endl;
}
