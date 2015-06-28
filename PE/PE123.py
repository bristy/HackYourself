# https://projecteuler.net/problem=123

from prime_util import sieve


MAX = 1000001
LIMIT = 10000000000
primes, s = sieve(MAX)
for i, p in enumerate(primes):
    if i % 2 == 0 and 2 * (i + 1) * p > LIMIT:
        print i + 1
        break
