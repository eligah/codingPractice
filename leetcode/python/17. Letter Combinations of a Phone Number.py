class Solution(object):
    def letterCombinations(self, digits):
        ans=[]
        if not digits:
            return ans
        keys=[ str(i) for i in range(10)]
        valuesnum=["","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]
        dic=dict(zip(keys,valuesnum))
        self.dfs(digits,"",ans,dic)
        return ans

    def dfs(self,n,str,ans,dic):
        if len(n)==0:
            ans.append(str)
            str=""
        else:
            d=n[0]
            for ch in dic[d]:
                ntr=str+ch
                self.dfs(n[1:],ntr,ans,dic)

s=Solution()
a=s.letterCombinations("34")
print(a)

