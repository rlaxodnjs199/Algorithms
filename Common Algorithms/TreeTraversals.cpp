#include <iostream>
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};
void InorderTraversal(TreeNode* head) {
  if (head == nullptr) return;
  InorderTraversal(head->left);
  std::cout << head->val << std::endl;
  InorderTraversal(head->right);
}
void PreorderTraversal(TreeNode* head) {
  if (head == nullptr) return;
  std::cout << head->val << std::endl;
  PreorderTraversal(head->left);
  PreorderTraversal(head->right);
}
void PostorderTraversal(TreeNode* head) {
  if (head == nullptr) return;
  PostorderTraversal(head->left);
  PostorderTraversal(head->right);
  std::cout << head->val << std::endl;
}