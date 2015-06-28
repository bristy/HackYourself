# https://oj.leetcode.com/problems/sum-root-to-leaf-numbers/


class TreeNode:
    """ Tree Node """
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    # @param root, a tree node
    # @return an integer
    def sumNumbers(self, root):
        if root is None:
            return 0
        else:
            return self.solve(root, "")

    def solve(self, root, path):
        if root.left is None and root.right is None:
            return int(path + str(root.val))
        else:
            ret = 0
            if root.left is not None:
                ret += self.solve(root.left, path + str(root.val))
            if root.right is not None:
                ret += self.solve(root.right, path + str(root.val))
            return ret

if __name__ == '__main__':
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    s = Solution()
    print s.sumNumbers(root)
