class Solution:
  def reverse(self, x):
    result = x
    if x < 0:
      result = -x
    rev = str(result)[::-1]
    for i in range(len(rev)):
      if rev[i] != 0:
        rev = int(rev[i:])
        break
    if rev > pow(2, 31):
      return 0
    return rev if x > 0 else rev * (-1)