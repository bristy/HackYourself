# https://projecteuler.net/problem=179


from prime_util import sieve


def consequtivePositiveDivisor():
    primes, s = sieve(3200)
    prev = 2
    ret = 0
    for i in xrange(3, 10000000):
        curr = getDivisorNumber(i, primes)
        if prev == curr:
            ret += 1
            # print i - 1, i
        # print prev, curr
        prev = curr
    print ret


def getDivisorNumber(n, primes):
    # print "for number  " + str(n)
    num = 1
    for e in primes:
        if e > n:
            break
        t = 0
        while n % e == 0:
            t += 1
            n /= e
        num = num * (t + 1)
    if n > 1:
        num *= 2
    return num


if __name__ == '__main__':
    consequtivePositiveDivisor()
    # primes, s = sieve(30)
    # print getDivisorNumber(3, primes)
    # print getDivisorNumber(10, primes)
    # print getDivisorNumber(16, primes)
    # print getDivisorNumber(20, primes)
