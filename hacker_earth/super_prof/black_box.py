def getSum(n):
    ret = 0
    while n > 0:
        ret += n % 10
        n /= 10
    return ret

fact = 1
ret = []
for i in xrange(1, 1001):
    fact *= i
    ret.append(getSum(fact))


t = int(raw_input())

for _ in xrange(t):
    n = int(raw_input())
    print ret[n - 1]
