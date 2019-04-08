/*
Problem:
Given a linked list, rotate the list to the right by k places, where k is non-negative.
*/
#include <iostream>
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
ListNode* rotateRight(ListNode* head, int k) {
  if (!k || !head) return head;
  ListNode* l1 = head;
  int length = 0;
  while (l1) {
    length++;
    l1 = l1->next;
  }
  l1 = head;
  ListNode* l2 = head;
  k %= length;
  while (k--) {
    l2 = l2->next;
  }
  while (l2->next) {
    l1 = l1->next;
    l2 = l2->next;
  }
  l2->next = head;
  ListNode* newhead = l1->next;
  l1->next = NULL;
  return newhead;
}