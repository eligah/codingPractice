class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        ndllen=len(needle)
        findex=haystack.find(needle)
        return findex