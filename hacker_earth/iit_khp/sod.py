n = int(raw_input())
s1 = 0
s2 = 0


def sod(s):
    ret = 0
    for el in s:
        ret += int(el)
    return ret

for i in xrange(n):
    s = raw_input()
    s1 += sod(s)
    s2 += int(s[-1])

ret = (s1 % 9 - s2 % 9 + 9) % 9
print ret
