## https://leetcode.com/problems/first-unique-character-in-a-string/
class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        duplicated={}
        for i in range(len(s)):
            if duplicated.get(s[i]):
                continue
            for j in range(i+1, len(s)):
                if s[i]==s[j]:
                    duplicated[s[i]]=1
                    break
            if not duplicated.get(s[i]):
                return i
        return -1
   
