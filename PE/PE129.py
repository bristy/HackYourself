# https://projecteuler.net/problem=112


from time import time


def isBouncy(s):
    ss = ''.join(sorted(s))
    rss = ''.join(sorted(s, reverse=True))
    if s == ss or s == rss:
        return False
    return True


start = time()
MAX = 99
cnt = 0
for t in xrange(1, 1600000):
    if isBouncy(str(t)):
        cnt += 1
    if cnt * 100 == MAX * t:
        print t
        break
print cnt
print time() - start
