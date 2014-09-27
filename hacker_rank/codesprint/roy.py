t = int(raw_input())
for test in xrange(t):
    line = [int(x) for x in raw_input().split(' ')]
    x = min(abs(line[0] - line[2]), abs(line[0] - line[4]))
    y = min(abs(line[1] - line[3]), abs(line[1] - line[5]))
    ret = min(x, y)
    print ret
