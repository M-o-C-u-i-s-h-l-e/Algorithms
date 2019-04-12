#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class Node {
public:
  int data;
  Node* next;
};

Node* detectCycle(Node* head) {
  if (head == NULL) return NULL;
  Node* first = head;
  Node* second = head->next;
  int power = 1;
  int length = 1;
  while (second != NULL && second != first) {
    if (length == power) {
      power *= 2;
      length = 0;
      first = second;
    }
    second = second->next;
    length++;
  }
  if (second == NULL) return NULL;
  first = second = head;
  while (length--)
    second = second->next;
  while (second != first) {
    second = second->next;
    first = first->next;
  }
  return first;
}

Node* newNode(int key) {
  Node* temp = (Node *)malloc(sizeof(Node));
  temp->data = key;
  temp->next = NULL;
  return temp;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  Node* head = newNode(50);
  head->next = newNode(20);
  head->next->next = newNode(15);
  head->next->next->next = newNode(4);
  head->next->next->next->next = newNode(10);
  head->next->next->next->next->next = head->next->next;
  Node *res = detectCycle(head);
  (res == NULL) ? cout << "No loop\n" : cout << "Loop is present at " << res->data << endl;
}
