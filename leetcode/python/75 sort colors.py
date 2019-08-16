from collections import  Counter
class Solution(object):
    def sortColors(self, nums):
        c=Counter(nums)
        res=[]
        d=dict(c)
        del nums[:]
        for k,v in dict(c).items():
            nums.extend(k for i in range(v))



s=Solution()
a=s.sortColors([0])
print(a)

