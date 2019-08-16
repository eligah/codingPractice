class Solution(object):
    def countPrimes(self, n):
        if n==0 or n==1:
            return 0
        reslist=[0 for i in range(n)]
        res=0
        for i in range(2,n):
            if reslist[i]==0:
                res+=1
                p=2
                while p*i<n:
                    reslist[p*i]=1
                    p+=1
        return res

s=Solution()
print(s.countPrimes(5))