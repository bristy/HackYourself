# https://www.hackerrank.com/contests/csindia14-er1/challenges/who-is-gone-be-first


s = raw_input()
n = len(s)
i = 0
prev = -1
l = 0
mx = 0
while i < n:
    # consume a
    l = 0
    while i < n and s[i] == 'a':
        l += 1
        i += 1
    if l > mx:
        mx = l
    i += 1
print 'a' * (mx + 1)
