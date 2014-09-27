# http://www.hackerearth.com/tcetcyphers-2/algorithm/little-vaishnavi-and-plywood-1/


t = int(raw_input())
for _ in xrange(t):
    m, k = (int(x) for x in raw_input().split(' '))
    jump = 0
    move = 0
    at = 0
    dir = 1
    while jump <= k:
        if at == 1:
            dir = 1
        if at == 5:
            dir = -1
        at += dir
        if at == m:
            jump += 1
        move += 1
    print move - 1
