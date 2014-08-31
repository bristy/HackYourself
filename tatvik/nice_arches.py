m = int(raw_input())
count = 0
for i in xrange(m):
    s = raw_input()
    index = 0
    ok = True
    while index <= len(s)/2:
        if s[index] != s[-index-1]:
            ok = False
            break
        index += 1
    if ok:
        count += 1

print count
