#!/usr/bin/env python
# -*- coding: UTF-8 -*-


class Solution:
    # @param {string} version1
    # @param {string} version2
    # @return {integer}
    def compareVersion(self, version1, version2):
        v1list = version1.split('.')
        v2list = version2.split('.')
        len1 = len(v1list)
        len2 = len(v2list)
        for ind in range(max(len1, len2)):
            if ind < len1:  # 以防数组越界
                v1 = int(v1list[ind])
            else:
                v1 = 0
            if ind < len2:  # 以防数组越界
                v2 = int(v2list[ind])
            else:
                v2 = 0
            if v1 < v2:
                return -1
            if v1 > v2:
                return 1
        return 0


## test code
if __name__ == "__main__":
    s=Solution()
    print s.compareVersion('1.25', '1.3')
    print s.compareVersion('1.25.3', '1.34.3')

