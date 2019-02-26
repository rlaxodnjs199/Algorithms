/*
Problem:
Given two non-empty linked-lists representing two non-negative
integers. The most significant digit comes first and each of
their nodes contains a single digit. Add two numbers and return
it as a linked list.
*/
#include <iostream>
#include <stack>
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x): val(x), next(nullptr) {}
};
ListNode* AddTwoNumsII(ListNode* l1, ListNode* l2) {
  std::stack<int> l1_stk;
  std::stack<int> l2_stk;
  ListNode* l1_itr = l1;
  ListNode* l2_itr = l2;
  while (l1_itr) {
    l1_stk.push(l1_itr->val);
    l1_itr = l1_itr->next;
  }
  while (l2_itr) {
    l2_stk.push(l2_itr->val);
    l2_itr = l2_itr->next;
  }
  ListNode* result = nullptr;
  int carry = 0;
  while (!l1_stk.empty() || !l2_stk.empty() || carry) {
    int sum = carry;
    if (!l1_stk.empty()) {
      sum += l1_stk.top();
      l1_stk.pop();
    }
    if (!l2_stk.empty()) {
      sum += l2_stk.top();
      l2_stk.pop();
    }
    carry = sum / 10;
    ListNode* temp = new ListNode(sum % 10);
    temp->next = result;
    result = temp;
  }
  return result;
}