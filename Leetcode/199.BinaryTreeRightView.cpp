#include <iostream>
#include <vector>
struct Node {
  int val;
  Node* left;
  Node* right;
  Node(int x): val(x), left(nullptr), right(nullptr) {}
};
class Solution {
  public:
    std::vector<int> BTRV(Node* root) {
      std::vector<int> result;
      int current_level = 0;
      int covered_level = -1;
      BTRV_helper(result, root, current_level, covered_level);
      return result;
    }
    void BTRV_helper(std::vector<int>& result, Node* root, int current_level, int& covered_level) {
      if (root == nullptr) return;
      if (current_level > covered_level) {
        result.push_back(root->val);
        covered_level++;
      }
      BTRV_helper(result, root->right, current_level+1, covered_level);
      BTRV_helper(result, root->left, current_level+1, covered_level);
    }
}
