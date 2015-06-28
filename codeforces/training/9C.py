# http://codeforces.com/problemset/problem/9/C


n = 0
ret = 0


def generate(num):
    global ret
    global n
    if int(num) > n:
        return
    ret += 1
    generate(num + '0')
    generate(num + '1')

n = int(raw_input())
generate('1')
print ret
