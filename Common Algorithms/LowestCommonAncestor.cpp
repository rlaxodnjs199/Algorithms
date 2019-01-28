/*LowestCommonAncestor in BinaryTree and BinarySearchTree*/
#include <iostream>
struct Node {
  int val;
  Node* left;
  Node* right;
  Node(int x): val(x), left(nullptr), right(nullptr) {}
};
//BinaryTree
class Solution {
  public:
    Node* lca(Node* root, Node* p, Node* q) {
      if (root == nullptr || root == p || root == q) return root;
      Node* left = lca(root->left, p, q);
      Node* right = lca(root->right, p, q);
      return root = (left && right)? root : left? left : right;
    }
};
//BinarySearchTree
class Solution {
  public:
    Node* lca1(Node* root, Node* p, Node* q) {
      if (root->val > p->val && root->val > q->val) return lca1(root->left, p, q);
      if (root->val < p->val && root->val < q->val) return lca1(root->right, p, q);
      return root;
    }
    Node* lca2(Node* root, Node* p, Node* q) {
      while (true) {
        if (root->val > p->val && root->val > q->val) {
          root = root->left;
        }
        else if (root->val < p->val && root->val < q->val) {
          root = root->right;
        }
        else {
          return root;
        }
      }
    }
}