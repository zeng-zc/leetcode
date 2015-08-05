# encoding: utf-8
# https://leetcode.com/problems/pascals-triangle/


class Solution:
        # @param {integer} numRows
        # @return {integer[][]}
        def generate(self, numRows):
            if numRows==0:
                return []
            if numRows==1:
                return [[1]]
            if numRows==2:
                return [[1], [1, 1]]
            res=self.generate(numRows-1)
            last=res[-1]
            length=len(last)
            last = [x+y for (x,y) in
             zip(last[0:length-1], last[1:])]
            last.insert(0, 1)
            last.append(1)
            res.append(last)
            return res

if __name__ == "__main__":
    import sys
    s = Solution()
    nrow = int(sys.argv[1])
#    print nrow
#    nrow=3
    res = s.generate(nrow)
    for x in res:
        print x
