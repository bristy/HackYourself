from linked_list import LinkedList


l = LinkedList()
l.makeList(10)
# l.display()
# l.getNth(2)
# l.getNth(11)
l.printMiddle()
l.getNthFromLast(10)
l.getNthFromLast(1)
l.getNthFromLast(3)
l.reverse()
l.display()
print l.detectLoop()

m = LinkedList()
m.push(1)
m.push(2)
m.push(1)
print m.isPalindrome()
