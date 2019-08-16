
class Solution(object):
    def maxRotateFunction(self, A):
        sumA=sum(A)
        lenA=len(A)
        vmax=0
        for i in range(lenA):
            vmax+=i*A[i]
        vmaxp=vmax
        for i in range(1,lenA):
            vmaxp=vmaxp+sumA-lenA*A[-i]
            vmax=max(vmax,vmaxp)
        return vmax

s=Solution()
a=s.maxRotateFunction([4,3,2,6])

print(a)