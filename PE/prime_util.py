#this modude hold all methods related to prime numbers

from math import sqrt
def is_prime(n):
    """ this method check if given number is prime or not """
    if n == 2 :
        return True

    if n < 2 or n % 2 == 0:
        return False

    for i in range(3, int(sqrt(n)+1), 2):
        if n % i == 0:
            return False

    return True
