"""
Let phi be Euler's totient function, i.e. for a natural number n, phi(n)
is the number of k, 1 <= k <= n, for which gcd(k,n) = 1.

By iterating phi, each positive integer generates a
decreasing chain of numbers ending in 1.
E.g. if we start with 5 the sequence 5,4,2,1 is generated.
Here is a listing of all chains with length 4:

5,4,2,1
7,6,2,1
8,4,2,1
9,6,2,1
10,4,2,1
12,4,2,1
14,6,2,1
18,6,2,1
Only two of these chains start with a prime, their sum is 12.

What is the sum of all primes less than 40000000
which generate a chain of length 25?
"""


MAX = 40000001
CHAIN = 25
phi = [0] * (MAX + 1)

for i in xrange(2, MAX):
    phi[i] = i

for i in xrange(2, MAX):
    if phi[i] == i:
        for j in xrange(i + i, MAX, i):
            phi[j] = phi[j] * (i - 1) / i
        phi[i] -= 1
req = []
for i in xrange(MAX):
    if phi[i] == CHAIN:
        req = i
print len(req)
