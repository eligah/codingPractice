class Solution(object):
    def __init__(self):
        self.res=[]
    def permute(self, nums):
        def permutehelper(nums,index):
            if index>=len(nums):
                self.res.append(nums[:])
            else:
                for i in range(index,len(nums)):
                    nums[index],nums[i]=nums[i],nums[index]
                    permutehelper(nums,index+1)
                    nums[index],nums[i]=nums[i],nums[index]
        if  not nums:
            return None
        permutehelper(nums,0)
        return self.res

s=Solution()
a=s.permute()
print(a)