class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        leftPare=set(['(','{','['])
        kindofPare=set(['(',')','{','}','[',']'])
        parelist=[pa for pa in s if pa in kindofPare]
        pstack=[]
        for p in parelist:
            if p in leftPare:
                pstack.append(p)
            else:
                if not pstack:
                    return False
                lfp=pstack.pop()
                if not self.isPair(lfp,p):
                    return False
        if  pstack:
            return False
        return True
                
    def isPair(self,lfp,rgp):
        if lfp=='{' and rgp=='}':
            return True
        if lfp == '[' and rgp == ']':
            return True
        if lfp == '(' and rgp == ')':
            return True
        return False
        
            
s=Solution()
a=s.isValid(']')
print(a)