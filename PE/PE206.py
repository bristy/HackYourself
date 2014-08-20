#http://projecteuler.net/problem=206

def check(n):
    """ check if number if of the form 1_2_3_4_5_6_7_8_9"""
    n = str(n)
    if len(n) != 17:
        return False
    else :
        bit = 1
        for i in range(17):
            if i %2 == 0:
                if n[i] != str(bit):
                    return False
                bit += 1

    return True

def solve():
    SOLVE = 19293949596979899
    n = 100000003
    while True:
        if check(n*n):
            print n
            break
        if n*n > SOLVE:
            print "not found exiting..."
            break
        if n %10 == 3:
            n += 4
        elif n %10 == 7:
            n += 6

if __name__ == '__main__':
    solve()
