#http://projecteuler.net/problem=56

def find_digit_sum(n):
    ret = 0
    while n > 0:
        ret += n%10
        n /=10
    return ret
def solve():
    ret = 0
    for a in range(1,100):
        for b in range(1, 100):
            s = find_digit_sum(a**b)
            if s > ret :
                ret = s

    print ret

if __name__ == '__main__':
    solve()

