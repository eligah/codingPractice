class Solution(object):
    def countAndSay(self, n):
        if n<10:
            return str(n)
        curcount=1
        curbit=1
        intlist=list(str(n))
        readlist=[]
        while curbit<len(intlist):
            if intlist[curbit-1] ==intlist[curbit]:
                curcount+=1
            else:
                readlist.append(str(curcount)+intlist[curbit-1])
                curcount=1
            curbit+=1
        readlist.append(str(curcount)+intlist[curbit-1])
        s=''.join(readlist)
        return s

s=Solution()
a=s.countAndSay(0)
print(a)




