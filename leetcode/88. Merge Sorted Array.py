class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        cntnum1=0
        cntnum2=0
        while cntnum1<m:
            if nums1[cntnum1]>=nums2[cntnum2]:
                nums1[m+cntnum2+cntnum1]=nums2[cntnum2]
                cntnum2+=1
            else:
                nums1[m+cntnum2+cntnum1]=nums1[cntnum1]
                cntnum1+=1
            if cntnum2==n:
                break
        if cntnum2==n:
            



