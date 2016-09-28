class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m,n=len(grid),len(grid[0])
        if m<1 or n<1:
            return  None
        for j in range(1,n):
            grid[0][j]+=grid[0][j-1]
        for i in range(1,m):
            grid[i][0]+=grid[i-1][0]
        for row in range(1,m):
            for col in range(1,n):
                grid[row][col]+=min(grid[row-1][col],grid[row][col-1])
        return grid[m-1][n-1]

s=Solution()
a=s.minPathSum([[1,2],[1,1]])
print(a)