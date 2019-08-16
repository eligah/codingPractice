class Solution(object):
    def __init__(self):
        self.result=[[]]

    def subsets(self, nums):
        if not nums:
            return
        self.result.append(nums)
        for i in nums:
            excepnums=nums[:]
            excepnums.remove(i)
            if excepnums not  in self.result:
                self.subsets(excepnums)

        return self.result

s=Solution()
a=s.subsets([1,2,3,4])
print(a)


