#include <iostream>
#include <stack>
struct Node {
  int val;
  Node* left;
  Node* right;
  Node(int x) : val(x), left(nullptr), right(nullptr) {}
};
int kthsmallest(Node* root, int k) {
  std::stack<Node*> node_stk;
  Node* node_itr = root;
  while (!node_stk.empty() || node_itr) {
    while (node_itr) {
      node_stk.push(node_itr);
      node_itr = node_itr->left;
    }
    if (--k == 0) {
      return node_stk.top()->val;
    }
    node_itr = node_stk.top()->right;
    node_stk.pop();
  }
  return -1;
}