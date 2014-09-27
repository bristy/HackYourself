# https://projecteuler.net/problem=78


DIV = 1000000
MAX = 500


def pe78():
    dp = [0] * MAX
    dp[0] = 1
    for i in xrange(1, MAX):
        w = i
        while w < MAX:
            dp[w] = dp[w] + dp[w - i]
            w += 1

    for n, v in enumerate(dp):
        if v % DIV == 0:
            print n, v
            break
    for i in xrange(20):
        print dp[i]
if __name__ == '__main__':
    pe78()
