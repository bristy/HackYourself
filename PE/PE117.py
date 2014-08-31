
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
        ret = 0
        for l in self.tileLen:
            ret += self.color(board-l)
        return ret

ret = 0

tiles = [1, 2, 3, 4]
paint = Paint(tiles)
ret = ret + paint.color(50)
print ret
