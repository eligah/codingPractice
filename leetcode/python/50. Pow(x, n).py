class Solution(object):
    def myPow(self, x, n):
        return 1/self.power(x,-n) if n<0 else self.power(x,n)

    def power(self,x,n):
        if n==0:
            return 1
        v = self.power(x, n // 2)
        return v * v * (x if n % 2 == 1 else 1)


s=Solution()
a=s.myPow(2,-3)
print(a)

