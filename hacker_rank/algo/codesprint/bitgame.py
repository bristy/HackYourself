def count(n):
    c = 0
    while n != 0:
        n &= (n - 1)
    c += 1
    return c


n = int(raw_input())
ret = 0
for i in range(n):
    ret ^= count(int(raw_input()))
if ret == 0:
    print "Shaka :)"
else:
    print "The other player :("
