# https://www.hackerrank.com/contests/infinitum-sep14/challenges/mehta-and-his-laziness


from sys import stdin
from fractions import gcd
from math import sqrt


def getInt():
    return map(int, stdin.readline().split())


def isPerfectSquare(n):
    lo = 0
    hi = n
    while (hi - lo) > 1:
        mid = (lo + hi) / 2
        if mid * mid == n:
            return mid
        elif mid * mid < n:
            lo = mid
        else:
            hi = mid - 1
    if hi * hi == n:
        return hi
    if lo * lo == n:
        return lo
    return -1


def isEvenPerfact(n):
    e = n % 10
    if e == 0 or e == 4 or e == 6:
        # return False if isPerfectSquare(n) == -1 else True
        s = int(sqrt(n))
        return s * s == n
    return False


t, = getInt()
for _ in xrange(t):
    n, = getInt()
    p = 0
    q = 1
    e = 2
    while e * e <= n:
        if n % e == 0:
            q += 1
            if isEvenPerfact(e):
                p += 1
            if e * e != n:
                q += 1
                if isEvenPerfact(n / e):
                    p += 1
        e += 1
    if p == 0:
        print p
    else:
        d = gcd(p, q)
        print str(p/d) + "/" + str(q/d)
