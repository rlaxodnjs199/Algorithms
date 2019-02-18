/*
Problem:
Given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse
order and each of their nodes contain a single digit.
Add two lists and return it as a linked list.

Idea:
We traverse two linked lists from heads. We find sum and
carry every loop, and declare new listnode with a single
digit from sum.

What I leared:
The reason we use heap allocation is because of the life
span of ListNode declared inside of function on the stack.
They lose information right after the function ends, so 
if we want to keep information in the main function after
calling addTwoNumbers, we need to declare information on heap.
*/
#include <iostream>
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x): val(x), next(nullptr) {}
  /*
  ListNode(int x) {
    this->val = x;
    this->next = nullptr;
  }
  */
};
class Solution {
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode dummy(1);
      ListNode* temp = &dummy;
      int carry = 0;
      while (l1 || l2) {
        int sum = carry;
        if (l1) {
          sum += l1->val;
          l1 = l1->next;
        }
        if (l2) {
          sum += l2->val;
          l2 = l2->next;
        }
        carry = sum / 10;
        sum = sum % 10;
        temp->next = new ListNode(sum);
        temp = temp->next;
      }
      if (carry) {
        temp->next = new ListNode(carry);
      }
      return dummy.next;
    }
};
int main() {
  Solution s;
  ListNode rl1(0);
  ListNode *l1 = &rl1;
  for (int i = 3; i > 0; i--) {
    l1->next = new ListNode(i);
    l1 = l1->next;
  }
  ListNode rl2(0);
  ListNode *l2 = &rl2;
  for (int i = 9; i > 3; i--) {
    l2->next = new ListNode(i);
    l2 = l2->next;
  }
  ListNode* ans = s.addTwoNumbers(rl1.next, rl2.next);
  while (ans) {
    std::cout << ans->val << std::endl;
    ans = ans->next;
  }
}