#http://projecteuler.net/problem=49

import prime_util
from string_util import is_permutation
from search_util import binary_search
def solve():
    #generate all 4 digits primes
    primes = [x for x in range(1000, 10000) if prime_util.is_prime(x)]
    n = len(primes)
    for i in range(n):
        for j in range(i+1, n):
            a = primes[i]
            b = primes[j]
            c = b + (b - a)
            if binary_search(primes, c) and check(str(a), str(b), str(c)):
                print a, b, c

    print len(primes)

def check(prime1, prime2, prime3):
    return is_permutation(prime1, prime2) and is_permutation(prime2, prime3) and is_permutation(prime3, prime1)
if __name__ == '__main__':
    solve()
