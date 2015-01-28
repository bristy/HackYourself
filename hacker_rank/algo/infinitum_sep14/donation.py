# https://www.hackerrank.com/contests/infinitum-sep14/challenges/little-chammys-huge-donation


from sys import stdin


def getInt():
    return map(int, stdin.readline().split())


def f(n):
    return n * (n + 1) * (2 * n + 1) / 6


def binarySearch(lo, hi, f, X):
    while (hi - lo) > 1:
        mid = (hi + lo) / 2
        if f(mid) <= X:
            lo = mid
        else:
            hi = mid - 1

    if f(hi) <= X:
        return hi
    else:
        return lo

t, = getInt()
for _ in xrange(t):
    X, = getInt()
    print binarySearch(0, X, f, X)
