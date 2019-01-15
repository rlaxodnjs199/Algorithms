#include <iostream>
#include <vector>
#include <cmath>
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution1 {
  public:
    std::vector<TreeNode*> generateTrees(int n) {
      return generateTreeshelper(1, n);
    }
    std::vector<TreeNode*> generateTreeshelper(int start, int end) {
      std::vector<TreeNode*> result;
      if (start > end) {
        result.push_back(nullptr);
        return result;
      }
      for (int i = start; i <= end; i++) {
        std::vector<TreeNode*> lefts = generateTreeshelper(start, i-1);
        std::vector<TreeNode*> rights = generateTreeshelper(i+1, end);
        for (int j = 0; j < lefts.size(); j++) {
          for (int k = 0; k < rights.size(); k++) {
            TreeNode* root = new TreeNode(i);
            root->left = lefts[j];
            root->right = rights[k];
            result.push_back(root);
          }
        }
      }
      return result;
    }
};
class Solution2 {
  public:
    TreeNode* clone(TreeNode* root) {
      if (root == nullptr) {
        return nullptr;
      }
      TreeNode* new_root = new TreeNode(root->val);
      new_root->left = clone(root->left);
      new_root->right = clone(root->right);
      return new_root;
    }
    void add_new_element(std::vector<TreeNode*>& temp_result, TreeNode* temp_root, int new_element) {
      //new_element is the new root
      TreeNode* new_root = new TreeNode(new_element);
      new_root->left = clone(temp_root);
      temp_result.push_back(new_root);
      //new_element is added to previous trees on right side
      TreeNode* temp_head = temp_root;
      while (temp_head != nullptr) {
        TreeNode* temp_right = temp_head->right;
        temp_head->right = new TreeNode(new_element);
        temp_head->right->left = temp_right;
        temp_result.push_back(clone(temp_root));
        temp_head->right = temp_right;
        temp_head = temp_head->right;
      }
    }
    void delete_tree(TreeNode* root) {
      if (root != nullptr) {
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
      }
    }
    std::vector<TreeNode*> generateTrees(int n) {
      std::vector<TreeNode*> result(1, nullptr);
      for (int i = 1; i <= n; i++) {
        int m = result.size();
        std::vector<TreeNode*> temp_result;
        for (int j = 0; j < m; j++) {
          add_new_element(temp_result, result[j], i);
          delete_tree(result[j]);
        }
        result = temp_result;
      }
      return result;
    }
}