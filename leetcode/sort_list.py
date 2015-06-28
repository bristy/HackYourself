# Definition for singly-linked list.ArithmeticError
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None



class Solution:

    def mergeSort(self, head):
        curr = head
        if head is None or head.next is None:
            return curr
        else :
            slow = curr
            fast = curr.next
            while fast is not None and fast.next is not None:
                slow = slow.next
                fast = fast.next
                fast = fast.next
            fast = slow.next
            slow.next = None
            left = self.mergeSort(curr)
            right = self.mergeSort(fast)
            return self.merge(left, right)

    def merge(self, first , second):
        head = ListNode(0) # temp sentinal node
        curr = head
        while first is not None and second is not None:
            if first.val < second.val:
                curr.next = first
                first = first.next
            else :
                curr.next = second
                second = second.next
            curr = curr.next

        if first is not None:
            curr.next = first
        if second is not None:
            curr.next = second

        return head.next

    # @param head, a ListNode
    # @return a ListNode
    def sortList(self, head):
        return self.mergeSort(head)


def driver():
    head = ListNode(10)
    head.next = ListNode(6)
    (head.next).next = ListNode(8)
    solution = Solution()
    head = solution.sortList(head)
    while head != None:
        print head.val
        head = head.next


if __name__ == '__main__':
    driver()
