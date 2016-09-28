class Solution(object):
    def plusOne(self, digits):
        if not digits:
            return [1]
        curbit=digits[-1]
        cnt=0
        size=len(digits)
        while cnt<size:
            if digits[size-1-cnt]!=9:
                digits[size-1-cnt]+=1
                break
            else:
                digits[size-1-cnt]=0
                cnt+=1
        if digits[0]==0:
            digits.insert(0,1)
        return digits


s=Solution()
a=s.plusOne([1,0])
print(a)