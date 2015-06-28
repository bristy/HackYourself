class PE120:
    def getMaxRemaider(self, a):
        ret = 0
        for n in xrange(1, 2*a+1):
            val = self.remainder(a, n)
            if ret < val:
                ret = val
        return ret

    def remainder(self, a, n):
        coeff = 0
        if n % 2 == 1:
            coeff = 2
        return ((2 - coeff) + n * a * coeff) % (a * a)

    def solve(self):
        r = 0
        for a in xrange(3, 1001):
            r += self.getMaxRemaider(a)

        print r


sol = PE120()
sol.solve()
print sol.getMaxRemaider(705)
