#include <iostream>
struct Node {
  int m_val;
  Node* m_left;
  Node* m_right;
  Node() {}
  Node(int val, Node* left, Node* right): m_val(val), m_left(left), m_right(right) {}
};

class Solution {
  public:
    Node* treeToDoublyList(Node* root) {
      if (!root) return NULL;
      Node* head;
      Node* prev;
      inorderconvert(head, prev, root);
      head->m_left = prev;
      prev->m_right = head;
      return head;
    }
    void inorderconvert(Node*& head, Node*& prev, Node* root) {
      if (!root->m_left) {
        head = root;
        prev = root;
      }
      if (root->m_left) inorderconvert(head, prev, root->m_left);
      Node* temp_left = root->m_left;
      Node* temp_right = root->m_right;
      prev->m_right = root;
      root->m_left = prev;
      prev = root;
      if (root->m_right) inorderconvert(head, prev, root->m_right);
    }
};