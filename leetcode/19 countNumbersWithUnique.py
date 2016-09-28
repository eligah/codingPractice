from functools import reduce
from operator import mul
class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        nump=1
        lprod=[1,]
        for i in range(1,10):
            nump*=i
            lprod.append(nump)
        lprod=[nump/i  for i in lprod]

        uniquenums=1
        while n>0:
            uniquenum=9*lprod[10-n]
            n-=1
            uniquenums+=uniquenum
        return int(uniquenums)
s=Solution()
a=s.countNumbersWithUniqueDigits(2)
print(a)