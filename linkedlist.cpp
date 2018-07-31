#include <iostream>
using namespace std;
Node* head;

class Node {
  public:
  int data;
  Node* next;
}
class LinkedList {
  public:
  LinkedList() {}
  void print();
  void reverseprint(Node* p);
  void insert(int data, int position);
  void delete(int position);
}

void LinkedList::print() {
  Node* temp;
  temp = head;
  while (temp != NULL) {
	cout << temp->data << endl;
	temp = temp->next;
  }
}

void LinkedList::reverseprint(Node* p) {
  if (p  == NULL) {
	return;
  }
  reverseprint(p->next);
  cout << p->data << endl;
}

void LinkedList::insert(int data, int position) {
  temp = new Node;
  temp->data = data;
  if (position == 1 && head == NULL) {
    temp->next = NULL;
    head == temp;
  }
  Node* temp2 = head;
  for (int i=0; i<position-1; i++) {
	temp2 = temp2->next;
  }
  temp->next = temp2->next;
  temp2->next = temp;
