class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count=1
        major=nums[0]
        for i in range(1,len(nums)):
            if major!=nums[i]:
                count-=1
                if count==0:
                    major=nums[i]
                    count+=1
            else:
                count+=1
        return major

s=Solution()
a=s.majorityElement([3,2,1,1,12,1])
print(a)
