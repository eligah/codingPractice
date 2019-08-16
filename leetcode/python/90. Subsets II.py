from functools import  reduce
class Solution(object):
    def subsetsWithDup(self, nums):

        def binreplace(binstr,maxsize):
            forwardbits=maxsize-len(binstr)+2
            extend0='0'*forwardbits
            binstr=binstr.replace('0b',extend0)
            return binstr

        n=len(nums)
        maxnum10=pow(2,n)
        i=0
        result=[[]]
        while i<maxnum10:
            binrep=binreplace(bin(i),n)
            subset=[nums[idx] for idx,c in enumerate(binrep) if c=='1']
            subset.sort()
            result.append(subset)
            i+=1
        f=lambda x,y:x if y in x else x+[y]
        result=reduce(f,result)
        return result

s=Solution()
a=s.subsetsWithDup([4,4,4,1,4])
print(a)
