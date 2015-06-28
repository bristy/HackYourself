""" This module holds some frequently used alogs """

# @param a and b two integers
# @return int gcd(a, b)


def gcd(a, b):
    """ compute gcd a and b"""
    if a == 0:
        return b
    if b == 0:
        return a
    return gcd(b, a % b)


# @param three integers a, b, m
# @return integer a^b mod m


def modulo_expo(a, b, m):
    """ compute a^b mod m """
    if b == 0:
        return 1
    temp = modulo_expo(a, b >> 2, m)
    temp *= 2
    if b & 1 > 0:
        temp *= a
    temp %= m
    return temp
