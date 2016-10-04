class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """

        ispos=True if x>=0 else False
        res=list(str(abs(x)))
        res.reverse()
        while len(res)>1:
            if res[0]=='0':
                del res[0]
                continue
            break
        num=''.join(res)
        num=int(num)
        num =num if ispos else -num
        if num>2**31-1 or num<-2**31:
            return 0
        return num
