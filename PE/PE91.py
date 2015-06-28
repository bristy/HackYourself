#http://projecteuler.net/problem=91

def is_right_angle(a, b, c):
    """ check if triangle is right angle or not
    squares of sides are given """
    if a == 0 or b == 0 or c == 0:
        return False
    else :
        return (a == b + c) or (b == c + a) or (c == a + b)

def square(a):
    return a*a

def solve():
    MAX = 51
    ret = 0
    for x1 in range(MAX):
        for y1 in range(MAX):
            for x2 in range(MAX):
                for y2 in range(MAX):
                    a = square(x1) + square(y1)
                    b = square(x2) + square(y2)
                    c = square(x1 - x2) + square(y1 - y2)
                    if is_right_angle(a, b, c):
                        ret += 1

    print ret/2


if __name__ == '__main__':
    solve()
