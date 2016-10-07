# https://leetcode.com/problems/is-subsequence/
class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        for c in s:
            pos = t.find(c)
            if pos==-1:
                return False
            t=t[pos+1:]
        return True    
        
