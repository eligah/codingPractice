class Solution(object):
    def rotate(self, matrix):
        n=len(matrix)
        # swap i,n-i-1 row
        i=0
        while i<n//2:
            matrix[i],matrix[n-i-1]=matrix[n-i-1],matrix[i]
            i+=1
        r=0
        while r<n:
            c=r+1
            while c<n:
                matrix[r][c],matrix[c][r]=matrix[c][r],matrix[r][c]
                c+=1
            r+=1

s=Solution()
a=s.rotate([[1,2],[3,4]])
print(a)