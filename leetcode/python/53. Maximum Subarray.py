class Solution(object):
    def maxSubArray(self, nums):
        dp=[nums[0]]
        for i in range(1,len(nums)):
            dp.append(nums[i]+dp[i-1] if dp[i-1]>0 else nums[i])
        return max(dp)