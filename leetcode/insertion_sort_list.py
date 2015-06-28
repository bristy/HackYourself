class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # @param head, ListNode
    # @return a ListNode
    def insertionSortList(self, head):
        if head is None or head.next is None:
            return head

        curr = head.next
        prev = head
        forward = curr.next
        while curr is not None and forward is not None:
            prev.next = curr.next

            # search where to place curr
            if head.val >= curr.val:
                curr.next = head
                head = curr
            else:
                left = head
                right = head.next
                while right is not None and right.val < curr.val:
                    left = right
                    right = right.next
                    self.insertNode(left, curr)
            curr = forward
            forward = forward.next
        return head

    def insertNode(self, after, node):
        """ insert node after after ListNode"""
        node.next = after.next
        after.next = node

    def driver(self):
        head = ListNode(10)
        head.next = ListNode(2)
        head.next.next = ListNode(5)
        head = self.insertionSortList(head)
        self.display(head)

    def display(self, head):
        curr = head
        while curr is not None:
            print curr.val
            curr = curr.next

solution = Solution()
solution.driver()
