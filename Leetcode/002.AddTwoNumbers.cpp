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