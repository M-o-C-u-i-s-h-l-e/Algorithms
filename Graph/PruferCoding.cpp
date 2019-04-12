#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void printTreeEdges(int prufer[], int m) {
  int vertices = m + 2;
  int vertex_set[vertices];
  fill_n(vertex_set, vertices, 0);
  for (int i = 0; i < vertices-2; i++)
    vertex_set[prufer[i]-1]++;
  cout << "Edges are: ";
  for (int i = 0; i < vertices-2; i++) {
    for (int j = 0; j < vertices; j++) {
      if (vertex_set[j] == 0) {
        vertex_set[j] = -1;
        cout << j+1 << "," << prufer[i] << "  ";
        vertex_set[prufer[i]-1]--;
        break;
      }
    }
  }
  int j = 0;
  for (int i = 0; i < vertices; i++) {
    if (vertex_set[i] == 0 && j == 0) {
      cout << i+1 << ",";
      j++;
    } else if (vertex_set[i] == 0 && j == 1) {
      cout << i+1 << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int prufer[] = {4, 1, 3, 4};
  int n = sizeof(prufer) / sizeof(prufer[0]);
  printTreeEdges(prufer, n);
}
