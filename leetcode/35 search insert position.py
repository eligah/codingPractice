class Solution(object):
    def searchInsert(self, nums, target):
        if not nums :
            return 0
        mid=len(nums)//2
        l=0
        r=len(nums)-1
        while l<=r:
            mid=(l+r)//2
            if nums[mid]>target:
                r=mid-1
            elif nums[mid]<target:
                l=mid+1
            else:
                return mid
        return l
s=Solution()
a=s.searchInsert([1,3,5],0)
print(a)
