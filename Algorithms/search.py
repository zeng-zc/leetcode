## https://leetcode.com/problems/search-in-rotated-sorted-array/
import bisect
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        min_pos = self.find_minimum(nums, 0, len(nums)-1)
        left = bisect.bisect_left(nums, target, 0, min_pos)
        if left!=min_pos and nums[left]==target:
            return left
        right = bisect.bisect_left(nums, target, min_pos)
        if right!=len(nums) and nums[right]==target:
            return right
        return -1
    def find_minimum(self, nums, beg, end):
        if beg >= end:
            return beg
        if nums[beg] < nums[end]:
            return beg
        mid = (beg+end)//2
        left = self.find_minimum(nums, beg, mid)
        right = self.find_minimum(nums, mid+1, end)
        return left if nums[left]<nums[right] else right
            
