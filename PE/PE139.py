# Pythagorean triplet
#http://projecteuler.net/problem=139

from math import sqrt
MAX = 100000000
def gcd(a, b):
    if b == 0:
        return a
    else :
        return gcd(b, a%b)


#n excluded
def solve(n):
    counter = 0
    for i in range(int(sqrt(n)) + 1):
        j = 1
        while j<i:
            if gcd(i,j) == 1 and (i-j)%2 != 0:
                a = i * i - j * j
                b = 2 * i * j
                c = i * i + j * j
                perim = a + b + c
                if perim < MAX and c % (b-a) == 0:
                    counter = counter + MAX/perim
            j += 1
    print counter


if __name__ == '__main__':
    solve(MAX)
