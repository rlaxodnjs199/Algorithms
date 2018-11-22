/*
1. Idea
we can simply iterate through the list
and reverse the pointers. Important thing here
is to initialize p1 and p2 to indicate two pointers
we use to manipulate pointers.
Iterative solution can finish the process in O(n) without
extra space.
Recursive solution can finish the process in O(2n) because
it first iterate through the list to the end and manipulate
the pointers in reversed order.
*/
#include <iostream>
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(NULL) {}
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution1 {
  public:
    ListNode* ReverseList(ListNode* head) {
      if (!head || !head->next) return head;
      ListNode* temp;
      ListNode* p1 = head;
      ListNode* p2 = head->next;
      p1->next = NULL;
      while (p2) {
        temp = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = temp;
      }
      return p1;
    }
};
//Initialize very first node as NULL and use it
//Same mechanism with Solution1 but more decent.
class Solution2 {
  public:
    ListNode* ReverseList(ListNode* head) {
      ListNode* prev = NULL;
      while (head) {
        ListNode* temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
      }
      return prev;
    }
};
class Solution3 {
  public:
    ListNode* ReverseList(ListNode* head) {
      //This ensures that it returns head when head->next = NULL
      //and doesn't do anything further.
      if (!head || !head->next) return head;
      //This stores pointer to the end element(which becomes newhead)
      //by executed until reaching last element.
      ListNode* newhead = ReverseList(head->next);
      //Since these two lines executed in the list with reversed order,
      //head->next->next properly overwrite head->next=NULL except
      //the last execution so that we can get right answer.
      head->next->next = head;
      head->next = NULL;
      return newhead;
    }
};