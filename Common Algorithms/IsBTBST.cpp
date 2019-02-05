#include <iostream>
struct Node {
  int val;
  Node* left;
  Node* right;
  Node(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
  public:
    bool isBTBST(Node* root, int max, int min) {
      if (root == nullptr) return true;
      if (root->val >= max || root->val <= min) return false;
      return isBTBST(root->left, root->val, min) && isBTBST(root->right, max, root->val);
    }
};