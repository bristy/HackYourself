"""
For a positive integer n, let sigma2(n) be the sum of
the squares of its divisors. For example,

sigma2(10) = 1 + 4 + 25 + 100 = 130.
Find the sum of all n, 0 < n < 64,000,000
such that sigma2(n) is a perfect square.
"""


from time import time
from math import sqrt


def isSquare(n):
    a = int(sqrt(n))
    return a * a == n

stime = time()
MAX = 64000000
LIMIT = 8000

sigma = [0] * (MAX + 1)

for i in xrange(2, LIMIT + 1):
    for j in xrange(i * i, MAX + 1, i):
        sigma[j] += i * i
        if i * i != j and j > i * LIMIT:
            sigma[j] += (j / i) * (j / i)

for i in xrange(2, MAX + 1):
    sigma[i] += i * i + 1
sigma[1] = 1
ret = 0
for i in xrange(1, MAX):
    if isSquare(sigma[i]):
        ret += i
print sigma[18]
print ret
print time() - stime
