class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        if len(nums)<=2:
            return max(nums)
        maxmoneys=nums[0:1]
        for idx,val in enumerate(nums[2:],2):
            maxmoneys.append(max(maxmoneys[idx-1],maxmoneys[idx-2]+val))
        return maxmoneys[-1]