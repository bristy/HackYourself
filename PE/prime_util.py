# this modude hold all methods related to prime numbers

from math import sqrt


# @param integer n
# @return True if n is prime else false


def is_prime(n):
    """ this method check if given number is prime or not """
    if n == 2:
        return True

    if n < 2 or n % 2 == 0:
        return False

    for i in range(3, int(sqrt(n)+1), 2):
        if n % i == 0:
            return False

    return True


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


# @param n have to calculate phi up to n
# @return a list of phi's

def euler_totient(n):
    phi = [0] * (n + 1)
    for i in xrange(2, n + 1):
        phi[i] = i
    for i in xrange(2, n + 1):
        if phi[i] == i:
            for j in xrange(i + i, n + 1, i):
                phi[j] = phi[j] * (i - 1) / i

    for i in xrange(2, n + 1):
        if phi[i] == i:
            phi[i] -= 1

    return phi
