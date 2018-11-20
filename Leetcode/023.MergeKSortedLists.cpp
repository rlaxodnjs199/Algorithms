/*
1. Idea
The Idea is to use priority_queue, 
which is implemented based on heap data structure.
It is more faster than repeating merging every two sorted lists 
because when we do that, the run time might be O(k^2) 
where k is the total number of entries of all elements in list nodes.
However, when we use priority_queue, inserting each element to the queue
takes O(log k) time, so the run time would be O(k logk).
*/

#include <iostream>
#include <queue>
#include <vector>
template<typename T> void print_ListNode (T& l) {
  std::cout << "[ ";
  while (l) {
    std::cout << l->val << " ";
  }
  std::cout << "]" << std::endl;
}
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};
struct comparison {
  bool operator()(const int& a, const int& b) {
    return a > b;
  }
};
class Solution {
  public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
      std::priority_queue<int, std::vector<int>, comparison> nums;
      for (auto& l : lists) {
        while (l) {
          nums.push(l->val);
          l = l->next;
        }
      }
      ListNode dummy(0);
      ListNode* head = &dummy;
      while (!nums.empty()) {
        head->next = new ListNode(nums.top());
        nums.pop();
        head = head->next;
      }
      return dummy.next;
    }
};
int main() {
  std::vector<ListNode*> lists;
  Solution s;
  ListNode* head = s.mergeKLists(lists);
  print_ListNode(head);
}