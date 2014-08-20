#http://projecteuler.net/problem=142

from math import sqrt
def is_perfect_square(n):
    a = int(sqrt(n))
    return a*a == n


def solve():
    MAX = 500
    for z in range(1,MAX):
        for y in range(z+1, MAX):
            for x in range(y+1, MAX):
                num = [x+y, x-y, x+z, x-z, y+z, y-z]
                done = True
                for el in num:
                    if not is_perfect_square(el):
                        done = False
                        break
                if done :
                    print x,y,z, x+y+z
                    return


if __name__ == '__main__':
    solve()


