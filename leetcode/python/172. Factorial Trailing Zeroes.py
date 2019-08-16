class Solution(object):
    def trailingZeroes(self, n):
        return 0 if n==0 else n//5+self.trailingZeroes(n//5)