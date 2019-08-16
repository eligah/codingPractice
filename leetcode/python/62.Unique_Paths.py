class Solution(object):
    def uniquePaths(self, m, n):
        array2=[[0 for col in range(n)] for row in range(m) ]
        array2[0][:]=[1 for l in range(n)]
        for row in range(m):
            array2[row][0]=1
        for row in range(1,m):
            for col in range(1,n):
                array2[row][col]=array2[row-1][col]+array2[row][col-1]
        return array2[m-1][n-1]