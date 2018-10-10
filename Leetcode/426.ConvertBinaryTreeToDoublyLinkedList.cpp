/*
1. Idea
First I was think about doing an inorder traversal first, 
then make a doubly linked list with the result of inorder traversal.
This is O(2*num of nodes) operation and needs O(n) extra space to
store the result of inorder traversal. To improve this, I have to
manipulate binary tree in place while doing an inorder traversal.
The problem is, we need to remember the beginning and latest element
of the doubly linked list for update. To do this, we need a container
function that has Node* head and Node* prev, and pass them to the
recursive function by reference so that they can be updated at the end
of each function calls. We can find head when there's no more root->left.
We can building a doubly linked list in the place where we usually print
Node element to do the inorder traversal: between left subtree function call
and right subtree function call. We connect current Node with prev Node to
form ta doubly linked list.
At the end, we connect head and end of the doubly linked list to make it circular.
*/

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