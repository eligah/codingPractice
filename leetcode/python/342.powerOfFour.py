class Solution(object):
    def isPowerOfFour(self, num):
        if num<=0:
            return False
        bitOne=0
        odd=True
        while num:
            if odd:
                if num & 1 == 1:
                    bitOne += 1
                    if bitOne > 1:
                        return False
                odd = False
            else:
                if num&1==1:
                    return False
                odd=True
            num=num>>1
        return True
s=Solution()
print(s.isPowerOfFour(64))