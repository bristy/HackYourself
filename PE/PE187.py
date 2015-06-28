# https://projecteuler.net/problem=187


from prime_util import sieve


def semiprime(n=100000000):
    primes, s = sieve(n)
    ret = 0
    for i, p in enumerate(primes):
        limit = n / p
        j = i
        while primes[j] <= limit:
            ret += 1
            j += 1

    print ret

if __name__ == '__main__':
    semiprime()
