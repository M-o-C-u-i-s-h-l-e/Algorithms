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

Node *findLCA(Node *root, int n1, int n2) {
  if (root == NULL) return NULL;
  if (root->key == n1 || root->key == n2)
    return root;
  Node *left_lca = findLCA(root->left, n1, n2);
  Node *right_lca = findLCA(root->right, n1, n2);
  if (left_lca && right_lca)  return root;
  return (left_lca != NULL) ? left_lca : right_lca;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);
  int n1, n2;
  cin >> n1 >> n2;
  cout << findLCA(root, n1, n2)->key << endl;
}
