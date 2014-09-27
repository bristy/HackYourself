t = int(raw_input())
for test in xrange(t):
    n = int(raw_input())
    lines = [int(x) for x in raw_input().split(' ')]
    c = [0] * 1000001
    for e in lines:
        c[e] += 1
    for i, e in enumerate(c):
        if i > 0:
            c[i] += c[i - 1]
    best = -1
    idx = 1
    for i, e in enumerate(lines):
        x = (i + 1) * c[e]
        if x >= best:
            best = x
            idx = i + 1
    print idx
