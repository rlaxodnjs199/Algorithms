/*
1. Idea
1) When we can manipulate LinkedList
Declare new ListNode on the stack and manipulate head->next to point it
after visiting it.
2) When we can't manipulate LinkedList
Declare two ListNode pointers: fast and slow. Let fast moves two times
faster than slow that eventually two pointers meet when there is a cycle
in the LinkedList.
*/
#include <iostream>
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution1 {
  bool CycleDetection(ListNode* head) {
    if (!head) return false;
    ListNode visited(0);
    while (head->next) {
      if (head->next == &visited) return true;
      ListNode* temp = head->next;
      head->next = &visited;
      head = temp;
    }
    return false;
  }
};
class Solution2 {
  bool CycleDetection(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (head && head->next) {
      fast = head->next->next;
      if (fast == slow) return true;
      slow = slow->next;
    }
    return false;
  }
}