class Solution(object):
    def rob(self, nums):
        if not nums:
            return 0
        if len(nums)<=2:
            return max(nums)
        return max(self.rob_helper(nums[:],0,len(nums)-1),self.rob_helper(nums[:],1,len(nums)))

    def rob_helper(self,nums,low,high):
        if not nums:
            return 0
        for idx in range(low,high):
            nums[idx]=max(nums[idx]+(nums[idx-2] if idx-2>=low else 0),(nums[idx-1] if idx-1>=low else 0))
        return nums[high-1]

s=Solution()
a=s.rob([2,1,1,2])
print(a)