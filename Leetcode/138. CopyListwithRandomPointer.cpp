/*
1. Deep copy vs Swallow copy
Swallow copy is just initializing a new pointer to the existing
component to act as a copy of it while not actually copying the
component. However, Deep copy initializes actual copy of existing
component in different location, therefore two of the original
component exist after finishing the copy.
2. Idea
First method I found was initializing a map of RandomListNode
and match original stuffs with copied stuffs. When copied stuffs
don't exist, we declare new one. When copied stuffs already
exist, we simply connect them in the right manner.
This is O(n) algorithm with O(n) extra memory space for map.
To avoid using extra memory, we should find another method.
The second I found was manipulating pointers of original components
and restore them later. It is like sewing two linked list.
This takes O(3*n) running time so slower than the first method but
we don't need any extra memory space.
3. Things I learned
In the linked list, sometimes I need to stop right before the end
element. I traverse through p1->next != NULL to avoid reaching last element.
Sometimes I need to reach last element but don't want to do certain task.
*/

#include <iostream>
struct RandomListNode {
  int label;
  RandomListNode* next;
  RandomListNode* random;
  RandomListNode(int x) {
    label = x;
    next = NULL;
    random = NULL;
  }
};
class Solution {
public:
  RandomListNode* copyRandomList(RandomListNode* head) {
    if (head == NULL) return NULL;
    RandomListNode* newhead, *p1, *p2;
    for (p1 = head; p1 != NULL; p1 = p1->next) {
      p2 = new RandomListNode(p1->label);
      p2->next = p1->random;
      p1->random = p2;
    }
    for (p1 = head; p1 != NULL; p1 = p1->next) {
      p2 = p1->random;
      p2->random = p2->next? p2->next->random : NULL;
    }
    newhead = p1->random;
    for (p1 = head; p1 != NULL; p1 = p1->next) {
      p2 = p1->random;
      p1->random = p2->next;
      // We don't want to access p1->next->random when
      // p1->next == NULL (Last element)
      p2->next = p1->next? p1->next->random : NULL;
    }
    return newhead;
  }
};