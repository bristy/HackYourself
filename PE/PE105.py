"""
et S(A) represent the sum of elements in set A of size n.
We shall call it a special sum set if for any two non-empty disjoint subsets,
B and C, the following properties are true:

S(B) != S(C); that is, sums of subsets cannot be equal.
If B contains more elements than C then S(B) > S(C).
For example, {81, 88, 75, 42, 87, 84, 86, 65} is not a special
sum set because 65 + 87 + 88 = 75 + 81 + 84, whereas
{157, 150, 164, 119, 79, 159, 161, 139, 158}
satisfies both rules for all possible subset pair combinations and S(A) = 1286.

Using sets.txt (right click and "Save Link/Target As..."),
a 4K text file with one-hundred sets containing seven to twelve elements
(the two examples given above are the first two sets in the file),
identify all the special sum sets, A1, A2, ..., Ak, and find
the value of S(A1) + S(A2) + ... + S(Ak).
NOTE: This problem is related to Problem 103 and Problem 106.
"""


fileName = "sets.txt"


def ruleOne(num):
    n = len(num)
    subset = [0] * (1 << n)
    for i in xrange(1, 1 << n):
        s = 0
        for j in xrange(i.bit_length()):
            if (1 << j) & i != 0:
                s += num[j]
        subset[i] = s
    for i in xrange(1, 1 << n):
        for j in xrange(i + 1, 1 << n):
            if i & j == 0 and subset[i] == subset[j]:
                return False
    return True


def ruleTwo(num):
    newNum = sorted(num)
    left = newNum[0]
    right = 0
    # print newNum
    n = len(num)
    for i in xrange(0, n/2):
        left += newNum[i + 1]
        right += newNum[n - i - 1]
        if left <= right:
            return False
    return True


f = open(fileName)
ret = 0
for line in f:
    num = map(int, line.split(','))
    if ruleOne(num) and ruleTwo(num):
        ret += sum(num)
print ret
