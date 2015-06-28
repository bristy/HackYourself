#http://projecteuler.net/problem=115

class PE115:
    MIN_RED_TILE_LEN = 50
    RED = 0
    BLACK = 1

    def __init__(self):
        self.cache = {}
    def count(self, tile, tileLen, totalLen):
        #base cases
        if totalLen == 0 or totalLen == tileLen:
            return 1
        if totalLen < tileLen:
            return 0

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
        n = 100
        while True:
            ret = self.count(self.BLACK, 0, n)
            if ret > 1000000:
                print ret, n
                break
            n += 1
if __name__ == '__main__':
    sol = PE115()
    sol.solve()
