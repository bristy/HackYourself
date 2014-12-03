# http://www.hackerearth.com/practice-contest-1-3/algorithm/find-the-divisors-2/

t = int(raw_input())

for _ in xrange(t):
    cnt = 0
    n = int(raw_input())
    i = 1
    while i * i <= n:
        if n % i == 0:
            cnt += 1
            if i * i != n:
                cnt += 1
        i += 1
    print cnt
