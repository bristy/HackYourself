t = int(raw_input())
for test in range(t):
    b = set(raw_input())
    w = set(raw_input())
    broken = {}
    ret = 0
    for key in w:
        if b.__contains__(key):
            ret += 1
    print ret
