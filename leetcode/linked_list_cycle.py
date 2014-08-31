class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None


class Solution:
    def hasCycle(self, head):
        slow = head
        fast = head
        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next

            if slow == fast:
                return True
        return False
