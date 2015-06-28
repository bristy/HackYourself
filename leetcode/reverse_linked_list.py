# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # @param head, a ListNode
    # @param m, an integer
    # @param n, an integer
    # @return a ListNode
    def reverseBetween(self, head, m, n):
        if head is None or m == n:
            return head
        newHead = ListNode(0)
        curr = newHead
        curr.next = head
        p = None
        i = 1
        while i <= n:
            if i < m:
                curr.next = head
                curr = curr.next
                head = head.next
                print "in less" + str(curr.val)
            elif i == m:
                p = head
                head = head.next
                print "in equal" + str(p.val)
            elif i <= n:
                temp = head
                head = head.next
                p.next = head
                temp.next = curr.next
                curr.next = temp
            i += 1
        return newHead.next

head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = ListNode(4)
sol = Solution()
head = sol.reverseBetween(head, 1, 3)
while head is not None:
    print head.val
    head = head.next
