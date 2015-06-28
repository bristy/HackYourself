class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None

class Solution:
    def reorder(self, head):
        if head is None or head.next is None:
            return head
        slow = head
        fast = head.next

        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next

        right = None  # sentinal node
        left = head
        fast = slow.next
        slow.next = None
        while fast is not None:
            temp = fast
            fast = fast.next
            if right is None:
                right = temp
                temp.next = None
            else:
                temp.next = right
                right = temp

        # interleave
        outList = ListNode(0)
        curr = outList
        while left is not None and right is not None:
            curr.next = left
            left = left.next
            curr = curr.next
            curr.next = right
            right = right.next
            curr = curr.next

        if left is not None:
            curr.next = left

        if right is not None:
            curr.next = right
        return outList.next

    def display(self, head):
        i = 0
        while head is not None and i < 10:
            print head.val
            head = head.next
            i += 1


s = Solution()
head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = ListNode(4)
head = s.reorder(head)
s.display(head)
