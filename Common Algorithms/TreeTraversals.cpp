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
#include <queue>
void LevelorderTraversal(TreeNode* head) {
  std::queue<TreeNode*> que;
  que.push(head);
  while (!que.empty()) {
    int level_count = que.size();
    while (level_count--) {
      TreeNode* temp = que.front();
      std::cout << temp->val << std::endl;
      que.pop();
      if (temp->left) que.push(temp->left);
      if (temp->right) que.push(temp->right);
    }
    std::cout << std::endl;
  }
}
#include <stack>
void IterativeInorder(TreeNode* head) {
  std::stack<TreeNode*> stk;
  TreeNode* cur_node = head;
  while (!stk.empty() || cur_node) {
    while (cur_node) {
      stk.push(cur_node);
      cur_node = cur_node->left;
    }
    cur_node = stk.top()->right;
    std::cout << stk.top()->val;
    stk.pop();
  }
}