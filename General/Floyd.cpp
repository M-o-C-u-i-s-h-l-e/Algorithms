#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class Node {
public:
  int data;
  Node *next;
  Node(int key) {
    this->data = key;
    this->next = NULL;
  }
};

bool detectCycle(Node *head) {
  Node *slow = head, *fast = head;
  while (slow && fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) return true;
  }
  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  Node* head = new Node(50);
  head->next = new Node(20);
  head->next->next = new Node(15);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(10);
  head->next->next->next->next->next = head->next->next;
  (detectCycle(head)) ? cout << "Yes\n" : cout << "No\n";
}
