#include <iostream>
struct Node {
  int val;
  Node* left;
  Node* right;
  Node(int x): val(x), left(nullptr), right(nullptr) {}
};
void insertion(Node* root, int target) {
  Node* temp = root;
  while (temp) {
    if (temp->val < target) {
      if (temp->right == nullptr) {
        temp->right = new Node(target);
        break;
      }
      else {
        temp = temp->right;
      }
    }
    else if (temp->val > target) {
      if (temp->left == nullptr) {
        temp->left = new Node(target);
        break;
      }
      else {
        temp = temp->left;
      }
    }
    else {
      std::cout << "target already exist!" << std::endl;
    }
  }
}
void insertion2(Node* root, int target) {
  if (root == nullptr) {
    root = new Node(target);
    return;
  }
  if (target < root->val) return insertion(root->left, target);
  if (target > root->val) return insertion(root->right, target);
}
void insertion3(Node* root, int target) {
  Node* parent = nullptr;
  Node* current = root;
  while (current) {
    parent = current;
    if (target < current->val) {
      current = current->left;
    }
    else if (target > current->val) {
      current = current->right;
    }
    else {
      std::cout << "Target already exist!" << std::endl;
    }
  }
}
bool sameTree(Node* root1, Node* root2) {
  if (root1 == nullptr && root2 == nullptr) return true;
  if (root1->val == root2->val) {
    return sameTree(root1->left, root2->left) && sameTree(root1->right, root2->right);
  }
  else {
    return false;
  }
}
int sizeTree(Node* root) {
  if (root == nullptr) return 0;
  return sizeTree(root->left) + sizeTree(root->right) + 1;
}
#include <algorithm>
int HeightTree(Node* root) {
  if (root == nullptr) return 0;
  return std::max(sizeTree(root->left), sizeTree(root->right)) + 1;
}
