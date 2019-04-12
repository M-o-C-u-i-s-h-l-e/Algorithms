#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define WHITE 1
#define BLACK 2
int V;

class Node {
public:
  int data;
  Node *left, *right;
  Node(int data) {
    this->data = data;
    this->left = this->right = NULL;
  }
};

class subset {
public:
  int parent, rank, ancestor, child, sibling, color;
};

class Query {
public:
  int L, R, LCA;
};

void makeSet(subset subsets[], int i) {
  if (i < 1 || i > V) return;
  subsets[i].color = WHITE;
  subsets[i].parent = i;
  subsets[i].rank = 0;
}

int findSet(subset subsets[], int i) {
  if (subsets[i].parent != i)
    subsets[i].parent = findSet(subsets, subsets[i].parent);
  return subsets[i].parent;
}

void unionSet(subset subsets[], int x, int y) {
  int xroot = findSet(subsets, x);
  int yroot = findSet(subsets, y);
  if (subsets[xroot].rank < subsets[yroot].rank)
    subsets[xroot].parent = yroot;
  else if (subsets[yroot].rank < subsets[xroot].rank)
    subsets[yroot].parent = xroot;
  else {
    subsets[yroot].parent = xroot;
    subsets[xroot].rank++;
  }
}

void lcaWalk(int u, Query q[], int m, subset subsets[]) {
  makeSet(subsets, u);
  subsets[findSet(subsets, u)].ancestor = u;
  int child = subsets[u].child;
  while (child != 0) {
    lcaWalk(child, q, m, subsets);
    unionSet(subsets, u, child);
    subsets[findSet(subsets, u)].ancestor = u;
    child = subsets[child].sibling;
  }
  subsets[u].color = BLACK;
  for (int i = 0; i < m; i++) {
    if (q[i].L == u) {
      if (subsets[q[i].R].color == BLACK)
        q[i].LCA = subsets[findSet(subsets, q[i].R)].ancestor;
    } else if (q[i].R == u) {
      if (subsets[q[i].L].color == BLACK)
        q[i].LCA = subsets[findSet(subsets, q[i].L)].ancestor;
    }
  }
}

void preprocess(Node *node, subset subsets[]) {
  if (node == NULL) return;
  preprocess(node->left, subsets);
  if (node->left != NULL && node->right != NULL) {
    subsets[node->data].child = node->left->data;
    subsets[node->left->data].sibling = node->right->data;
  } else if (node->left != NULL && node->right == NULL) {
    subsets[node->data].child = node->left->data;
  } else if (node->right != NULL && node->right == NULL) {
    subsets[node->data].child = node->right->data;
  }
  preprocess(node->right, subsets);
}

void initialize(subset subsets[]) {
  memset(subsets, 0, (V+1) * sizeof(subset));
  for (int i = 1; i <= V; i++)
    subsets[i].color = WHITE;
}

void LCAs(Node *root, Query q[], int m) {
  subset *subsets = new subset[V+1];
  initialize(subsets);
  preprocess(root, subsets);
  lcaWalk(root->data, q, m, subsets);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  V = 5;
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  int m;
  cin >> m;
  Query q[m];
  for (int i = 0; i < m; i++)
    cin >> q[i].L >> q[i].R;
  LCAs(root, q, m);
  for (int i = 0; i < m; i++)
    cout << q[i].L << "-" << q[i].R << "  " << q[i].LCA << endl;
}
