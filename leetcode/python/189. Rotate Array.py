from collections import deque
class Solution(object):
    def rotate(self, nums, k):
        time=k%len(nums)
        while time!=0:
            movetail=nums.pop()
            nums.insert(0,movetail)
            time-=1
        return nums
s=Solution()
a=s.rotate([1,2,3],5)
print(a)