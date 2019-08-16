#
# class Solution(object):
#     def isIsomorphic(self, s, t):
#         if len(s)!=len(t):
#             return False
#         mmap=t.maketrans(s,t)
#         t2=s.translate(mmap)
#         if t2==t:
#             return True
#         else:
#             return False

import string
class Solution(object):
    def isIsomorphic(self, s, t):
        if len(s)!=len(t):
            return False
        maps=[-1]*256
        mapt=[-1]*256
        for idx in range(len(s)):
            if maps[ord(s[idx])]!=mapt[ord(t[idx])]:
                return False
            mapt[ord(t[idx])]=ord(t[idx])
            maps[ord(s[idx])]=ord(t[idx])
        return True
s=Solution()
a=s.isIsomorphic('ssq','qas')
print(a)
