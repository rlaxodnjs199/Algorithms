#include <iostream>
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL){}
};
class Solution {
  public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode dummy(0);
      ListNode* head = &dummy;
      while (l1 && l2) {
        if (l1->val <= l2->val) {
          head->next = l1;
          l1 = l1->next;
        }
        else {
          head->next = l2;
          l2 = l2->next;
        }
        head = head->next;
      }
      head->next = l1? l1 : l2;
      return dummy.next;
    } 
};
int main() {
  Solution s;
  ListNode l1(0);
  ListNode* head1 = &l1;
  ListNode l2(1);
  ListNode* head2 = &l2;
  for (int i = 1; i < 6; i++) {
    head1->next = new ListNode(i);
    head1 = head1->next;
    head2->next = new ListNode(i+1);
    head2 = head2->next;
  }
  ListNode* mergedhead = s.mergeTwoLists(l1.next, l2.next);
  while (mergedhead->next) {
    std::cout << mergedhead->val << "->";
    mergedhead = mergedhead->next;
  }
  std::cout << mergedhead->val;
}

/*
1. Idea
To merge two sorted arrays, we need to declare a new head
and then start to go through the two sorted arrays, pick smaller one
and attach it to the new head again and again.
2. Attention!
When passing two arrays, we need to use 'new' keyword to store the data
in a heap rather than just declare ListNode in stack memory.
This prevents data to be safely delivered to the function call.
3. Elegant syntax
head->next = l1? l1 : l2;
When l1 reaches nullptr, head->next = l2
Otherwise, head->next = l1.
*/