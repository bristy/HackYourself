# http://www.hackerearth.com/tcetcyphers-2/algorithm/vaishnav-and-pizzas/


LIMIT = 10010
phi = [i for i in xrange(LIMIT)]
for i in xrange(2, LIMIT):
    if phi[i] == i:
        j = i
        while j < LIMIT:
            phi[j] = phi[j] / i * (i - 1)
            j += i

for i in xrange(2, LIMIT):
    phi[i] += phi[i - 1]

t = int(raw_input())
for _ in xrange(t):
    n = int(raw_input())
    print phi[n] - 1
