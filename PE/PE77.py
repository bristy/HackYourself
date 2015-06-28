# https://projecteuler.net/problem=77


from prime_util import sieve

MAX = 5000
INF = 1 << 31


def pe77():
    primes, s = sieve(MAX)
    dp = [0] * MAX
    dp[0] = 1
    for p in primes:
        w = p
        while w < MAX:
            dp[w] = dp[w] + dp[w - p]
            w += 1
    for i, p in enumerate(dp):
        if p > 5000:
            print i, p
            break

if __name__ == '__main__':
    pe77()
