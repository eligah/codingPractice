class Solution(object):
    def isPalindrome(self, x):
        def palindromehelper(x,bitnum):
            revnum=len(x)-bitnum-1
            l=x//pow(10,revnum)
            r=x

        if x<10 and x>=0:
            return True
        if x<0:
            return False
        else:
            l=x//pow(10,(len(str(x))-1))
            r=x%10
            if l!=r:
                return False
            else:
                newx = x - l * pow(10,len(str(x))-1)
                newx//=10
                return self.isPalindrome(newx)

s=Solution()
a=s.isPalindrome(1000021)
# a2=s.isPalindrome(-1)
# a3=s.isPalindrome(10)
# a4=s.isPalindrome(11)
# for x in [a,a2,a3,a4]:
#     print(x)

print(a)
