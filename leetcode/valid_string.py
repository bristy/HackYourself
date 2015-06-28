# https://oj.leetcode.com/problems/valid-parentheses/
class Solution:
    # @return a boolean
    def isValid(self, s):
        stack = []
        start = ['(', '{', '[']
        finish = {'(': ')', '{': '}', '[': ']'}
        for e in s:
            print e
            if e in start:
                #print "appending"
                stack.append(e)
            elif len(stack) > 0 and e == finish[stack[-1]]:
                #print "poping"
                stack.pop()
            else:
                return False
        if len(stack) == 0:
            return True
        else:
            return False
s = Solution()
s.isValid("()")
