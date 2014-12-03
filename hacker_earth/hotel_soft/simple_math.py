from math import factorial
mod = 10000007
line = raw_input().split(' ')
n = int(line[0])
r = int(line[1])
if n < r:
    print "-1"
else:
    n = n - r
    n = n + r - 1
    r = r - 1
    fac = factorial(n)
    fac /= factorial(r)
    fac /= factorial(n - r)
    fac %= mod
    print fac
