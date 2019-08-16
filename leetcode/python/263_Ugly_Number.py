class Solution(object):

    def isUgly(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num==1 or num==0:
            return True
        num=self.divide(num,2)
        num=self.divide(num,3)
        num=self.divide(num,5)
        if num==1:
            return True
        else:
            return False



    def divide(self,num,div):
        num,res=divmod(num,div)
        while not res:
            num,res=divmod(num,div)
        return num*div+res

s=Solution()
print(s.isUgly(7))