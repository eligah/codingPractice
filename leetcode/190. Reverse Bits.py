class Solution(object):
    def reverseBits(self, n):
        if not n:
            return 0
        bit=0
        bitContainer=[]
        while  n or bit:
            n,bit=divmod(n,2)
            bitContainer.append(bit)
        if bitContainer[-1]==0:
            bitContainer.pop()
        while len(bitContainer)!=32:
            bitContainer.append(0)
        bitidx=0
        res=0
        for bitidx in bitContainer:
            res=res*2+bitidx
        return res

s=Solution()
print(s.reverseBits(2147483648))