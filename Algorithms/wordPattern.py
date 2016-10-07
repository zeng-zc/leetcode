# https://leetcode.com/problems/word-pattern/
## 一一映射关系，用一个正向hashtable和一个反向哈希表
class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        hashtable={}
        reversehash={}
        strlist = str.split()
        if len(strlist) != len(pattern):
            return False
        for i in range(len(strlist)):
            value=hashtable.get(strlist[i])
            if value:
                if value!=pattern[i]:
                    return False
            else:
                if reversehash.get(pattern[i]):
                    return False
                hashtable[strlist[i]] = pattern[i]
                reversehash[pattern[i]] = strlist[i]
        return True


## 解法二：都映射成[1,2,2,1]这样的形式。好处是代码可以复用
## 参见另一个文件的 C++ 实现，使用函数模板
class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        return self.mapToList(pattern) == self.mapToList(str.split())
    
    def mapToList(self, str):
        """
        : abba --> 1221
        """
        ret = []
        hashtable = {}
        i=0
        for c in str:
            if not hashtable.get(c):
                i+=1
                hashtable[c] = i
            ret.append(hashtable[c])
        return ret
