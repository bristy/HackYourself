# https://projecteuler.net/problem=76


class Solve:

    def count(self, n):
        dp = [0]*(n + 1)
        dp[0] = 1
        for c in range(1, n):
            for w in range(c, n + 1):
                    dp[w] = dp[w] + dp[w - c]
        return dp[n]

s = Solve()
print s.count(100)
