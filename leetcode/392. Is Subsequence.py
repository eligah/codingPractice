class Solution(object):
    def isSubsequence(self, s, t):
        startidx = 0
        try:
            for letter in s:
                startidx = t.index(letter, startidx)+1
        except ValueError as e:
            return False
        return True


s = Solution()
sa = ""
a = s.isSubsequence("leeeeetcode", 'letcode')
print(a)
