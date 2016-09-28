class Solution(object):
    def findDuplicate(self, nums):
        nums=sorted(nums)
        for i in range(len(nums)-1):
            if nums[i]==nums[i+1]:
                return nums[i]