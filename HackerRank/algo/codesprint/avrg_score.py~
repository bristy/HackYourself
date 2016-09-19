t = int(raw_input())
for test in xrange(t):
    line = [int(x) for x in raw_input().split(' ')]
    n = line[0]
    del(line[0])
    avg = sum(line)
    ret = 0
    for e in line:
        if len(line) * e > avg:
            ret += 1
    print ret
