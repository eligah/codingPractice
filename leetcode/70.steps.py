class Solution(object):
    def climbStairs(self, n):
        if n==1:
            return 1
        steps=[0,1,2]
        for i in range(3,n+1):
            steps.append(steps[i-1]+steps[i-2])
        return steps[n]