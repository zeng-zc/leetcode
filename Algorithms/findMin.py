# https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        idx = self.find_minimum(nums, 0, len(nums)-1)
        return nums[idx]
    def find_minimum(self, nums, beg, end):
        if beg >= end:
            return beg
        if nums[beg] < nums[end]:
            return beg
        mid = (beg+end)//2
        left = self.find_minimum(nums, beg, mid)
        right = self.find_minimum(nums, mid+1, end)
        return left if nums[left]<nums[right] else right
        
