t = int(raw_input())
for tt in range(t):

    n, m = map(int, raw_input().split())
    mice = [int(x) for x in raw_input().split(' ')]
    holes = [int(x) for x in raw_input().split(' ')]
    ret = -1
    mice.sort()
    holes.sort()
    for m, h in zip(mice, holes):
        ret = max(ret, abs(m - h))
    print ret
