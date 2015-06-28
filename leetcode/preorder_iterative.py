class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


class Solution:
    def preorderTraversal(self, root):
        stack = []
        nodes = []
        if root is None:
            return nodes
        else:
            stack.append(root)
            while len(stack) > 0:
                curr = stack.pop()
                nodes.append(curr.val)
                if curr.right is not None:
                    stack.append(curr.right)
                if curr.left is not None:
                    stack.append(curr.left)

            return nodes


root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)

sol = Solution()
print sol.preOrderTraversal(root)
