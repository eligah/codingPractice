class Solution(object):
    def convertletter(self,bit):
        if bit<=9:
            return str(bit)
        else:
            return chr(ord(str(bit-10))-ord('0')+ord('a'))

    def toHex(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num<0:
            num+=2**32
        reslist=[]
        num,rest=divmod(num,16)
        reslist.insert(0,self.convertletter(rest))
        while num>0:
            num,rest= divmod(num,16)
            reslist.insert(0,self.convertletter(rest))
        return ''.join(reslist)

s=Solution()
a=s.toHex(-1)
print(a)

