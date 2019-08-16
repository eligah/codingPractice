from leetcode import  TreeNode
from operator import mul
class Solution(object):
    def numTrees(self, n):
        if n==0:
            return 0
        res=[1,1]
        resr=[1,1]
        cnt=1
        while cnt<n:
            item=sum(map(mul,res,resr))
            res.append(item)
            resr.insert(0,item)
            cnt+=1
        return res[n]

s=Solution()
a=s.numTrees(1)
print(a)