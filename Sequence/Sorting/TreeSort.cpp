#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class Node {
public:
  int key;
  Node *left, *right;
  Node(int key) {
    this->key = key;
    this->left = this->right = NULL;
  }
};

void print(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void storeSorted(Node *root, int arr[], int &i) {
  if (root != NULL) {
    storeSorted(root->left, arr, i);
    arr[i++] = root->key;
    storeSorted(root->right, arr, i);
  }
}

Node *insert(Node *node, int key) {
  if (node == NULL)
    return new Node(key);
  if (key < node->key)
    node->left = insert(node->left, key);
  else if (key > node->key)
    node->right = insert(node->right, key);
  return node;
}

void treeSort(int arr[], int n) {
  Node *root = NULL;
  root = insert(root, arr[0]);
  for (int i = 1; i < n; i++)
    insert(root, arr[i]);
  int i = 0;
  storeSorted(root, arr, i);
  print(arr, n);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  treeSort(arr, n);
}
