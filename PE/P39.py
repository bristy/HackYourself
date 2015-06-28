def solve():
    mx = 0
    best = 0
    for p in range(25,1001):
        ret = 0
        for a in range(1,p):
            q = p*(p-2*a)
            d = 2*(p-a)
            if q%d == 0:
                ret += 1
        if ret > best:
            best = ret
            mx = p
    print str(best) + "  " + str(mx)

if __name__ == '__main__':
	solve()
