class ListNode(object):
  def __init__(self, x):
    self.val = x
    self.next = None
class Solution(object):
  def addTwoNumbers(self, l1, l2):
    carry = 0
    root = itr = ListNode(0)
    while l1 or l2 or carry:
      sum = carry
      if l1:
        sum += l1.val
        l1 = l1.next
      if l2:
        sum += l2.val
        l2 = l2.next
      carry, sum = divmod(sum, 10)
      itr.next = ListNode(sum)
      itr = itr.next
    return root.next