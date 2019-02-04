#include <iostream>
#include <vector>
struct Node {
  int val;
  Node* left;
  Node* right;
  Node(int x): val(x), left(nullptr), right(nullptr) {}
};
bool RootToLeafSum(Node* root, int target, int sum, std::vector<int>& result) {
  if (root == nullptr) return false;
  sum += root->val;
  if (sum == target) {
    result.push_back(root->val);
    return true;
  }
  if (RootToLeafSum(root->left, target, sum, result) || RootToLeafSum(root->right, target, sum, result)) {
    result.push_back(root->val);
    return true;
  }
  return false;
}
void RootToLeafSum2(Node* root, int target, int sum, std::vector<std::vector<int>>& result, std::vector<int>& temp) {
  if (root == nullptr) return;
  sum += root->val;
  temp.push_back(root->val);
  if (sum == target) {
    result.push_back(temp);
  }
  RootToLeafSum2(root->left, target, sum, result, temp);
  RootToLeafSum2(root->right, target, sum, result, temp);
  temp.pop_back();
}
int main() {
  Node* Root = new Node(10);
  Root->left = new Node(16);
  Root->right = new Node(5);
  Root->left->right = new Node(-3);
  Root->right->left = new Node(6);
  Root->right->right = new Node(11);
  std::vector<int> result;
  if (RootToLeafSum(Root, 26, 0, result)) {
    for (auto i : result) {
      std::cout << i << " ";
    }
  }
  std::cout << std::endl;
  std::vector<std::vector<int>> result2;
  std::vector<int> temp;
  RootToLeafSum2(Root, 26, 0, result2, temp);
  for (auto vec : result2) {
    for (auto i : vec) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
}