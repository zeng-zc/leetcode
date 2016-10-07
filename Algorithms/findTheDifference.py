## https://leetcode.com/problems/find-the-difference/

## use stardard library collections.Counter
from collections import Counter
class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        c1 = Counter(s)
        c2 = Counter(t)
        return (c2-c1).keys().pop()
