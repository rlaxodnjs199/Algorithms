#include <iostream>
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
  public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* p1 = head;
      ListNode* p2 = head;
      while (n--) {
        p1 = p1->next;
      }
      if (!p1) {
        return head->next;
      }
      while (p1->next) {
        p1 = p1->next;
        p2 = p2->next;
      }
      p2->next = p2->next->next;
      return head;
    }
};
int main() {
  ListNode* temp = new ListNode(1);
  ListNode* head = temp;
  for (int i = 2; i < 6; i++) {
    temp->next = new ListNode(i);
    temp = temp->next;
  }
  Solution s;
  ListNode* result = s.removeNthFromEnd(head, 2);
  while (result) {
    std::cout << result->val << "->";
    result = result->next;
  }
}

/*
1. Idea
To do this in one-pass, we need to declare two pointers to the head and set difference between two by n. First proceed p1 for n times and then proceed both p1 and p2 until p1->next reaches a nullptr. The only special case is that removing first element of the linked list. In this case, p1 already reaches nullptr so accessing p1->next invokes segment default error. When p1 already reaches nullptr, we can simply return head->next to skip first element.
*/