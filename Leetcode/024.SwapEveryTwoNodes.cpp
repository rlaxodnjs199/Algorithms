#include <iostream>
template<typename T> void print_ListNode(T& l) {
  std::cout << "[ ";
  while (l) {
    std::cout << l->val << " ";
    l = l->next;
  }
  std::cout << "]" << std::endl;
}
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
  public:
    ListNode* swapPairs(ListNode* head) {
      ListNode dummy(0);
      ListNode* temphead = &dummy;
      while (head) {
        ListNode* firstofPairs = head;
        if (head->next) {
          head = head->next;
          firstofPairs->next = head->next;
          head->next = firstofPairs;
        }
        temphead->next = head;
        temphead = firstofPairs;
        head = temphead->next;
      }
      return dummy.next;
    }
};
int main() {
  Solution s;
  ListNode dummy(0);
  ListNode* head = &dummy;
  for (int i = 0; i < 9; i++) {
    head->next = new ListNode(i);
    head = head->next;
  }
  ListNode* ptr = s.swapPairs(dummy.next);
  print_ListNode(ptr);
}

/*
1. Idea
To swap every two adjacent nodes, we need to carefully
organize how to manipulate given pointers.
First, I need to store first pointer of the pair to use later.
Also we need to access pointer->next only when pointer is not a NULLptr.
Since we need to access two proceeding pointers each time, we need to
establish an if statement to only access second proceeding pointer
when first proceeding pointer is valid.
Then everything else is just a reassigning of pointers.
We only need O(1) space ( To store first of the pairs),
and the run time is O(n) since we can finish this in one-pass.
*/