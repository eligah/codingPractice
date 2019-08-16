class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels=set(['a','e','i','o','u','A','E','I','O','U'])
        extravowels=[]
        posl=[]
        for idx,l in enumerate(s,0):
            if l in vowels:
                extravowels.append(l)
                posl.append(idx)
        extravowels.reverse()
        slist=list(s)
        for idx,i in enumerate(posl):
            slist[i]=extravowels[idx]
        return ''.join(slist)

s=Solution()
a=s.reverseVowels('aA')
print(a)