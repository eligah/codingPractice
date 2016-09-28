class Solution(object):
    def searchMatrix(self, matrix, target):
        m,n=len(matrix),len(matrix[0])
        frow=0
        lrow=n-1
        while mid<lrow:
            mid=(frow+lrow)//2+1
            if matrix[mid][0]==target:
                return True
            if matrix[mid][0]<target:
                frow=mid
            if matrix[mid][0]>target:
                lrow=mid-1
        if target in matrix[lrow]:
            return True
        return False

s=Solution()
a=s.searchMatrix([[1,2],[1,1]],2)
print(a)

