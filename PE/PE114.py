#http://projecteuler.net/problem=114

class PE114:
    MIN_RED_TILE_LEN = 3
    MAX = 50
    RED = 0
    BLACK = 1

    def __init__(self):
        self.cache = {}
    def count(self, tile, tileLen, totalLen):
        #base cases
        if totalLen == 0:
            return 1
        if totalLen < tileLen:
            return 0
        if totalLen == tileLen:
            return 1

        if (tile, tileLen, totalLen) in self.cache:
            return self.cache[(tile, tileLen, totalLen)]
        if tile == self.RED:
            ret = 0
            ret += self.count(1-tile, 1, totalLen - tileLen)
            self.cache[(tile, tileLen, totalLen)] = ret
            return ret
        else :
            ret = 0
            for x in xrange(self.MIN_RED_TILE_LEN, totalLen+1):
                ret += self.count(1 - tile, x, totalLen - tileLen)
            ret += self.count(tile, 1, totalLen - tileLen)
            self.cache[(tile, tileLen, totalLen)] = ret
            return ret

    def solve(self):
        ret = self.count(self.BLACK, 0, self.MAX)
        print ret
if __name__ == '__main__':
    sol = PE114()
    sol.solve()
