# http://www.hackerearth.com/tcetcyphers-2/algorithm/vaishnav-and-factorials/


import sys
from math import factorial as f

t = int(sys.stdin.readline())
for _ in xrange(t):
    n = int(sys.stdin.readline())
    s = str(f(n))
    ret = 0
    for e in s:
        if e == '4' or e == '7':
            ret += 1
    print ret
