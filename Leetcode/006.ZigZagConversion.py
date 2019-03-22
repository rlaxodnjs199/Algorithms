class Solution(object):
  def convert(self, s, numRows):
    if numRows == 1 or numRows >= len(s):
      return s
    List = [''] * numRows
    index = 0
    step = 1
    for c in s:
      List[index] += c
      if index == 0:
        step = 1
      elif index == numRows -1:
        step = -1
      index += step
    return ''.join(List)