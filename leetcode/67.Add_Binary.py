class Solution(object):
    def addBinary(self, a, b):
        if  (a == b) and a=='0':
            return '0'
        int10A,int10B=0,0
        sumall=self.getint10(a)+self.getint10(b)
        return self.convert2bin(sumall)

    def getint10(self, a):
        int10A=0
        for i in a:
            int10A*=2
            if i == '1':
                int10A += 1
        return int10A

    def convert2bin(self,num):
        result=[]
        while num>0:
            num,rest=divmod(num,2)
            result.append(str(rest))
        result.reverse()
        return ''.join(result)

s=Solution()
a=s.addBinary('0','0')
print(a)