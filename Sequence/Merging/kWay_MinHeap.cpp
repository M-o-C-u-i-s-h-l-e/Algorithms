#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define n 4

class Node {
public:
  int element, i, j;
};

class MinHeap {
public:
  Node *harr;
  int heap_size;
  MinHeap(Node a[], int size) {
    heap_size = size;
    harr = a;
    int i = (heap_size - 1) / 2;
    while (i >= 0)
      minHeapify(i--);
  }
  void minHeapify(int i);
  int left(int i) { return (2*i + 1); }
  int right(int i) { return (2*i + 2); }
  Node getMin() { return harr[0]; }
  void replaceMin(Node x) { harr[0] = x; minHeapify(0); }
};

void MinHeap::minHeapify(int i) {
  int l = left(i);
  int r = right(i);
  int smallest = i;
  if (l < heap_size && harr[l].element < harr[i].element) smallest = l;
  if (r < heap_size && harr[r].element < harr[smallest].element)  smallest = r;
  if (smallest != i) {
    swap(harr[i], harr[smallest]);
    minHeapify(smallest);
  }
}

int *mergeKArrays(int arr[][n], int k) {
  int *output = new int[n*k];
  Node *harr = new Node[k];
  for (int i = 0; i < k; i++) {
    harr[i].element = arr[i][0];
    harr[i].i = i;
    harr[i].j = 1;
  }
  MinHeap hp(harr, k);
  for (int Count = 0; Count < n*k; Count++) {
    Node root = hp.getMin();
    output[Count] = root.element;
    if (root.j < n) {
      root.element = arr[root.i][root.j];
      root.j += 1;
    } else {
      root.element = INT_MAX;
    }
    hp.replaceMin(root);
  }
  return output;
}

void print(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int arr[][n] = {
    {2, 6, 12, 34},
    {1, 9, 20, 1000},
    {23, 34, 90, 2000}
  };
  int k = sizeof(arr) / sizeof(arr[0]);
  int *output = mergeKArrays(arr, k);
  print(output, n*k);
}
