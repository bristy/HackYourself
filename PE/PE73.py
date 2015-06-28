"""
Consider the fraction, n/d, where n and d are positive integers.
If n<d and HCF(n,d)=1, it is called a reduced proper fraction.
If we list the set of reduced proper fractions for d <= 8 in
ascending order of size, we get:

1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2,
 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8

It can be seen that there are 3 fractions between 1/3 and 1/2.

How many fractions lie between 1/3 and 1/2 in the sorted
set of reduced proper fractions for d <= 12,000?
"""


from fractions import gcd
from time import time


def cmpLess(a, b):
    return a[0] * b[1] < a[1] * b[0]

stime = time()
L = (1, 3)
R = (1, 2)
MAX = 12001
cnt = 0
for i in xrange(2, MAX):
    for j in xrange(i/3, 2 * i / 3):
        if gcd(i, j) == 1:
            # frac = (j, i)
            # if cmpLess(frac, R) and cmpLess(L, frac):
            cnt += 1
            # if cmpLess(R, frac):
            #    break

print cnt
print time() - stime
