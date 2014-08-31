class PE78:

    def __init__(self):
        #self.count = self.memoize(self.count)
        self.cache = {}
    def memoize(self, fun):
        memo = {}
        def helper(n):
            if n not in memo:
                memo[n] = fun(n)
            return fun(n)
        return helper


    def count(self, n):
        if n < 0:
            return 0
        if n == 0:
            return 1
        if n in self.cache:
            return self.cache[n]
        ret = 0
        for el in xrange(1, n+1):
            ret += self.count(n - el)
        self.cache[n] = ret
        return ret

solution = PE78()
print solution.count(5)
n = 10000
while True:
    cnt = solution.count(n)
    if cnt % 1000000 == 0:
        print n
        break
    if n > 11000:
        print "limit reached {}".format(n)
        break
    n += 1
