/*
Problem:
Given a linked list, return a node where cycle begins.
Return null if there is no cycle.
*/
#include <iostream>
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x): val(x), next(nullptr) {}
};
ListNode* detectcycle(ListNode* head) {
  ListNode* slow = head;
  ListNode* fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      ListNode* entry = head;
      while (entry != slow) {
        entry = entry->next;
        slow = slow->next;
      }
      return entry;
    }
  }
  return nullptr;
}