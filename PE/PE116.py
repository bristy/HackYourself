
class Paint:

    def __init__(self, tileLen):
        self.tileLen = tileLen
        self.color = self.memoize(self.color)

    def memoize(self, f):
        memo = {}

        def helper(x):
            if x not in memo:
                memo[x] = f(x)
            return memo[x]
        return helper

    def color(self, board):
        if board == 0:
            return 1
        if board < 0:
            return 0
        return (self.color(board-1) + self.color(board - self.tileLen))

ret = 0

print "for 2"
paint = Paint(2)
ret = ret + paint.color(50) - 1
print ret

print "for 3"
paint = Paint(3)
ret = ret + paint.color(50) - 1
print ret


print "for 4"
paint = Paint(4)
ret = ret + paint.color(50) - 1

print ret
