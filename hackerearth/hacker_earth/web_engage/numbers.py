# http://www.hackerearth.com/webengage-hiring-challenge-1/algorithm/ankit-and-numbers-8/


from sys import stdin


def getInt():
    return map(int, stdin.readline().split())


t, = getInt()
for _ in xrange(t):
    n, = getInt()
    print 2 ** (n - 1) * n * (n + 1) / 2
