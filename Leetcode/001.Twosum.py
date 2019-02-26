# enumerate(nums): return (index, element)
class Solution(object):
  def twoSum(self, nums: 'List[int]', target: 'int') -> 'List[int]':
    checker = {}
    for i, num in enumerate(nums):
      if target - num in checker:
        return [i, checker[target - num]]
      else:
        checker[num] = i
    return []