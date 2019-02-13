#include <iostream>
struct Node {
  int val;
  Node* left;
  Node* right;
  Node(int x): val(x), left(nullptr), right(nullptr) {}
};
int LBB(Node* root, int max, int min, int& result) {
  if (root->left == nullptr && root->right == nullptr) {
    return 1;
  }
  if (root->left == nullptr || root->left->val > max) {
    if (root->right->val > min) {
      int temp_result = LBB(root->right, max, root->val, result) + 1;
      result = std::max(result, temp_result);
      return temp_result;
    }
    else return 1;
  }
  if (root->right == nullptr || root->right->val < min) {
    if (root->left->val < max) {
      int temp_result = LBB(root->left, root->val, min, result) + 1;
      result = std::max(result, temp_result);
      return temp_result;
    }
  }
  if (root->left->val < max && root->right->val > min) {
    int temp_result = LBB(root->right, max, root->val, result) + LBB(root->left, root->val, min, result) + 1;
    result = std::max(result, temp_result);
    return result;
  }
  return 1;
}
int main() {
  Node* root = new Node(25);
  root->left = new Node(18);
  root->right = new Node(50);
  root->left->left = new Node(19);
  root->left->right = new Node(20);
  root->left->left->right = new Node(15);
  root->left->right->left = new Node(18);
  root->left->right->right = new Node(25);
  root->right->left = new Node(35);
  root->right->right = new Node(60);
  root->right->right->left = new Node(55);
  root->right->right->right = new Node(70);
  root->right->left->left = new Node(20);
  root->right->left->right = new Node(40);
  root->right->left->left->right = new Node(25);
  int result = 0;
  LBB(root, root->val, root->val, result);
  std::cout << result;
}