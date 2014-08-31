t = int(raw_input())
for x in xrange(t):
    n = int(raw_input())
    nums = [int(el) for el in raw_input().split(" ")]
    a = [-1]*10
    b = [-1]*10
    for e, v in enumerate(nums):
        if a[v] == -1:
            a[v] = e
            b[v] = e
        else:
            b[v] = e

    ret = 0
    for i in xrange(10):
        if a[i] != -1 and b[i] != -1:
            ret = max(ret, b[i] - a[i] + 1)
    print ret
