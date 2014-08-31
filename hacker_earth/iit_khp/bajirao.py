from math import factorial
t = int(raw_input())
for x in xrange(t):
    line = [int(n) for n in raw_input().split(" ")]
    n = line[0]
    k = line[1]
    MAX = 107
    ret = 0
    if n <= MAX:
        ret = n
        for kk in xrange(k):
            if ret >= MAX:
                ret = 0
                break
            ret = factorial(ret)
    print ret % MAX
