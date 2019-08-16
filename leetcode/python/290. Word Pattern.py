class Solution(object):
    def wordPattern(self, pattern, str):
        strlist=str.split()
        if len(pattern)!=len(strlist):
            return False
        dictmap={}
        for idx,word in enumerate(strlist):
            if pattern[idx] in dictmap.keys():
                if dictmap[pattern[idx]]!=word:
                    return False
                continue
            else:
                if word in dictmap.values():
                    return False
                dictmap[pattern[idx]]=word
        return True