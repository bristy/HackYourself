# https://projecteuler.net/problem=282


def memo(f):
    cache = {}

    def helper(m, n):
        if (m, n) not in cache:
            cache[(m, n)] = f(m, n)
        return cache[(m, n)]
    return helper


@memo
def A(m, n):
    if m == 0:
        return n + 1
    if n == 0:
        return A(m - 1, 1)
    return A(m - 1, A(m, n - 1))
ret = 0
for i in xrange(7):
    ret += A(i, i)
