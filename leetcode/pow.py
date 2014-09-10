class Solution:
    # @param x, a float
    # @param n, a integer
    # @return a float
    def pow(self, x, n):
        if n < 0 :
            return self.calc(1/x, -n)
        else:
            return self.calc(x, n)
    
    def calc(self, x, n):
        if n == 0:
            return 1
        temp = self.pow(x, n>>1)
        temp = temp * temp
        if n %2 == 1:
            temp *= x
        return temp
        
