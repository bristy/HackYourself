# http://www.hackerearth.com/webengage-hiring-challenge-1/algorithm/amazing-test/


from sys import stdin


def getInt():
    return map(int, stdin.readline().split())


def solve():
    n, x = getInt()
    A = getInt()
    A.sort()
    s = sum(A)
    W = [False] * (s + 1)
    W[0] = True
    for e in A:
        for w in xrange(s, e - 1, -1):
            W[w] = W[w] or W[w - e]
    ret = 100000000
    # print W
    for i, w in enumerate(W):
        if w:
            ret = min(ret, max(i, s - i))
    if ret <= x:
        print "YES"
    else:
        print "NO"


if __name__ == '__main__':
    t, = getInt()
    for _ in xrange(t):
        solve()
