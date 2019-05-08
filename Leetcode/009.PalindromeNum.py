class Solution(object):
  def isPalindrome(self, x):
    if x < 0:
      return False
    rev = 0
    x_copy = x
    while x_copy:
      rev = rev * 10 + x_copy % 10
      x_copy /= 10
    return rev == x