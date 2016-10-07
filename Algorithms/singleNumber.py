## https://leetcode.com/problems/single-number/
import functools as ft
import operator
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return ft.reduce(operator.xor, nums)

## python 的 reduce， 类似于C++中的 std::accumulate
## python 和 C++ 都是一行代码搞定
