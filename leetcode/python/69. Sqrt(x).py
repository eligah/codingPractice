
# 小心溢出
class Solution(object):
    def mySqrt(self, x):
        if x==0:
            return 0
        l=0
        r=x
        mid=(l+r)//2
        while l<=r:
            mid=(l+r)//2
            if mid>x/mid:
                r=mid-1
            elif mid<x/mid:
                l=mid+1
            else:
                return mid
        return r

s=Solution()
a=s.mySqrt(0)
print(a)