#http://projecteuler.net/problem=49

import prime_utils

def solve():
    #generate all 4 digits primes
    primes = [x for x in range(1000, 100000) if prime_utile.is_prime(x)]

    print len(primes)
