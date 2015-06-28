from list_node import ListNode


class LinkedList:
    def __init__(self):
        self.head = None

    def push(self, val):
        """ Push a node with value val at end """
        if self.head is None:
            self.head = ListNode(val)
        else:
            current = self.head
            while current.next is not None:
                current = current.next
            current.next = ListNode(val)

    def makeList(self, count):
        """ Create a list with count node or append if
        list already exists """
        for x in xrange(1, count+1):
            self.push(x)

    def display(self):
        """ Print the list """
        print "Printing List :"
        current = self.head
        while current is not None:
            print current.val
            current = current.next

    def getNth(self, n):
        """ get nth node form start """
        current = self.head
        while current is not None and n > 1:
            current = current.next
            n -= 1

        if current is not None:
            print current.val
        else:
            print "No such node exist"

    def getNthFromLast(self, n):
        """ get nth node from last """
        main = self.head
        ref = self.head
        while n > 0:
            if ref is None:
                print "Greater than total number of nodes"
                return
            ref = ref.next
            n -= 1
        while ref is not None:
            ref = ref.next
            main = main.next
        print main.val

    def printMiddle(self):
        """ Print middle element of the list """
        slow = self.head
        fast = self.head
        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next

        if slow is not None:
            print slow.val
        else:
            print "no such element"

    def reverse(self):
        """ Reverse the list """
        current = self.head
        next = None
        prev = None
        while current is not None:
            next = current.next
            current.next = prev
            prev = current
            current = next
        self.head = prev

    def detectLoop(self):
        """ Detect Loop in list """
        if self.head is not None:
            slow = self.head
            fast = self.head
            while (slow is not None and
                   fast is not None and fast.next is not None):
                slow = slow.next
                fast = fast.next.next
                if slow == fast:
                    return True
            return False

    def isPalindrome(self):
        """ check if list is palindrome
            it modifies current list
        """
        if self.head is None or self.head.next is None:
            return True

        slow = self.head
        fast = self.head
        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next
        if fast is None:
            slow = slow.next
        fast = slow
        slow = self.head

        # reverse second half
        next = None
        prev = None
        curr = fast
        while curr is not None:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        fast = prev

        while fast is not None:
            if fast.val != slow.val:
                return False
            fast = fast.next
            slow = slow.next

        return True
