from leetcode import TreeNode


class Solution(object):
    def sortedArrayToBST(self, nums):
        return self.BulidTree(nums, 0, len(nums) - 1)

    def BulidTree(self, nums, start, end):
        if start > end:
            return None
        if start == end:
            return TreeNode(nums[start])
        mid = (start + end) // 2
        root = TreeNode(nums[mid])
        root.left = self.BulidTree(nums,start, mid - 1)
        root.right = self.BulidTree(nums,mid + 1, end)
        return root



s=Solution()
a=s.sortedArrayToBST([1])
print(a)