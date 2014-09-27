# http://www.hackerearth.com/webengage-hiring-challenge-1/
# algorithm/numbers-of-interest-2-1/


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
            if i * i <= n:
                primes.append(i)
    return (primes, s)


def solve():
    MAX = 1000010
    x = [0, 0]
    y = [0, 0]
    primes, ss = sieve(MAX)
    print len(primes)
    for n in xrange(2, MAX):
        if ss[n]:
            x.append(n)
            y.append(1)
            continue
        first = True
        s = 0
        for p in primes:
            if p < n:
                if n % p == 0:
                    if first:
                        x.append(p)
                        first = False
                    t = 0
                    while n % p == 0:
                        t += 1
                        n /= p
                    if t > 0:
                        s += (p ** (t + 1) - 1) / (p - 1)
        if n > 1:
            s += (p + 1)
        y.append(s - n)
    print "ready"
    f = [0]
    for i in xrange(1, MAX):
        f.append(f[-1] + x[i])
    g = [0]
    for i in xrange(1, MAX):
        g.append(g[-1] + y[i])
    t, = getInt()
    for _ in xrange(t):
        nn, = getInt()
        print (f[nn] + g[nn]) % nn


if __name__ == '__main__':
    solve()
