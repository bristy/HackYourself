# http://www.hackerearth.com/practice-contest-1-3/algorithm/generate-the-primes-2/

from sys import stdin


def getInt():
    return map(int, stdin.readline().split())


# @param integer n
# list of primes below n


def sieve(n):
    primes = list()
    s = [True] * n
    s[0] = s[1] = False
    for i in xrange(2, n):
        if s[i]:
            j = i * i
            while j < n:
                s[j] = False
                j += i
            primes.append(i)
    return (primes, s)


MAX = 10000000
primes, s = sieve(MAX)
t, = getInt()
for _ in xrange(t):
    n = getInt() - 1
    print primes[n]
