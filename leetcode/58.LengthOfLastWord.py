import re
class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        s=s.strip()
        if not s:
            return 0
        return len(re.split('\s+',s)[-1])

s=Solution()
print(s.lengthOfLastWord(''))