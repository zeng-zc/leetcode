## https://leetcode.com/problems/sum-of-left-leaves/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

## 解法一：递归，左孩子由调用者来特殊处理，稍微有点麻烦
## 单节点树直接返回0
class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root or (not root.right and not root.left):
            return 0
        rightsum = self.sumOfLeftLeaves(root.right)
        if root.left and not root.left.left and not root.left.right: 
            return root.left.val + rightsum
        else:
            return self.sumOfLeftLeaves(root.left) + rightsum

# 解法二：递归，写一个辅助函数，调用者传一个参数来标记root节点是否为左孩子。更简单
## 单节点树的返回值取决于参数标记是否为左孩子
class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        return self.helper(root.left, True) + self.helper(root.right, False)
    def helper(self, root, isleftchild):
        if not root:
            return 0
        if not root.left and not root.right:
            if isleftchild:
                return root.val
            else:
                return 0
        return self.helper(root.left, True) + self.helper(root.right, False)
