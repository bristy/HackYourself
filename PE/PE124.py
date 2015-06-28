"""
The radical of n, rad(n), is the product of the distinct prime factors of n.
For example, 504 = 23 * 32 * 7, so rad(504) = 2 * 3 * 7 = 42.

If we calculate rad(n) for 1 <= n <= 10, then sort them on rad(n),
and sorting on n if the radical values are equal, we get:

Let E(k) be the kth element in the sorted n column;
for example, E(4) = 8 and E(6) = 9.

If rad(n) is sorted for 1 <= n <= 100000, find E(10000).
"""


MAX_N = 100000
primeProd = [0] * (MAX_N + 1)
for i in xrange(1, MAX_N + 1):
    primeProd[i] = 1

for i in range(2, MAX_N + 1):
    if primeProd[i] == 1:
        for j in xrange(i + i, MAX_N + 1, i):
            primeProd[j] *= i
        primeProd[i] = i

E = []
for i in xrange(MAX_N + 1):
    E.append((primeProd[i], i))  # (prod, index)
# print E
E.sort()
print "(prod, index)"
print E[10000]
# print E
