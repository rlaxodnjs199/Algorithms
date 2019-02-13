#include <iostream>
#include <stack>
#include <deque>
#include <queue>
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

void LevelorderTraversal(TreeNode* head) {
  std::queue<TreeNode*> que;
  que.push(head);
  while (!que.empty()) {
    int level_count = que.size();
    while (level_count--) {
      TreeNode* temp = que.front();
      std::cout << temp->val << " ";
      que.pop();
      if (temp->left) que.push(temp->left);
      if (temp->right) que.push(temp->right);
    }
    std::cout << std::endl;
  }
}
void LevelorderReverse(TreeNode* head) {
  std::stack<TreeNode*> node_stk;
  std::queue<TreeNode*> node_que;
  node_que.push(head);
  TreeNode* node_itr = head;
  while (!node_que.empty()) {
    int level_count = node_que.size();
    while (level_count--) {
      TreeNode* temp = node_que.front();
      node_stk.push(temp);
      node_que.pop();
      if (temp->right) node_que.push(temp->right);
      if (temp->left) node_que.push(temp->left);
    }
  }
  while (!node_stk.empty()) {
    std::cout << node_stk.top()->val << " ";
    node_stk.pop();
  }
}
void LevelorderSpiral(TreeNode* root) {
  std::deque<TreeNode*> node_dq;
  node_dq.push_back(root);
  while (!node_dq.empty()) {
    int level_count = node_dq.size();
    int current_count = 0;
    while (current_count != level_count) {
      TreeNode* temp = node_dq.front();
      node_dq.pop_front();
      std::cout << temp->val << " ";
      if (temp->left) node_dq.push_back(temp->left);
      if (temp->right) node_dq.push_back(temp->right);
      current_count++;
    }
    std::cout << std::endl;
    level_count = node_dq.size();
    current_count = 0;
    while (current_count != level_count) {
      TreeNode* temp = node_dq.back();
      node_dq.pop_back();
      std::cout << temp->val << " ";
      if (temp->right) node_dq.push_front(temp->right);
      if (temp->left) node_dq.push_front(temp->left);
      current_count++;
    }
    std::cout << std::endl;
  }
}

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
void IterativePostorder(TreeNode* head) {
  std::stack<TreeNode*> stk;
  TreeNode* cur = head;
  TreeNode* last = nullptr;
  while (!stk.empty() || cur) {
    if (cur) {
      stk.push(cur);
      cur = cur->left;
    }
    else {
      if (stk.top()->right && last != stk.top()->right) {
        cur = stk.top()->right;
      }
      else {
        std::cout << stk.top()->val;
        last = stk.top();
        stk.pop();
      }
    }
  }
}
void IterativePreorder(TreeNode* head) {
  TreeNode* node_itr = head;
  std::stack<TreeNode*> node_stk;
  while (!node_stk.empty() || node_itr) {
    if (node_itr) {
      std::cout << node_itr;
      node_stk.push(node_itr);
      node_itr = node_itr->left;
    }
    else {
      node_itr = node_stk.top()->right;
      node_stk.pop();
    }
  }
}

int main() {
  TreeNode* root = new TreeNode(10);
  root->left = new TreeNode(6);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(11);
  root->left->right->left = new TreeNode(5);
  LevelorderSpiral(root);
}