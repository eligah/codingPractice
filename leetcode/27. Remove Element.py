class Solution(object):
    def removeElement1(self, nums, val):
        nums=list(filter(lambda x:x!=val,nums))
        print(nums)
        return len(nums)

    def removeElement2(self, nums, val):
        try:
            while nums:
                nums.remove(val)
        except:
            return len(nums)
    def removeElement3(self,nums,val):
        index=0
        i=0
        while i<len(nums):
            if nums[i]!=val:
                nums[index]=nums[i]
                index+=1
            i+=1
        nums=nums[:index]
        return index

s=Solution()
a=s.removeElement1([3,2,2,3],2)
print(a)