
found = False
def gen(prev ,n, d):
    global found
    if found :
        return
    if len(prev) == n:
        
        #print int(prev)/d
        if int(prev)%d == 0:
            print prev
            found = True
        return
    if(not found):
        gen(prev+'0', n,d)
        gen(prev+'9', n,d)


def solve():
    global found
    t = int(raw_input())
    while t>0:
        t -= 1
        found = False
        n = int(raw_input())
        if 9%n == 0:
            print '9'
        else:
            i = 2
            while not found:
                gen('9',i,n)
                i += 1
if __name__=='__main__':
    found = False
    #gen('9', 4, 11)
    solve()
