from functools import reduce
class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows==1:
            return s
        container=[]
        strlen=len(s)
        groupwidth=numRows-1
        groupnum=strlen//(2*numRows-2)+1
        numCols=groupnum*(numRows-1)
        # reslist=[([0]*numCols) for i  in range(numRows)]
        reslist=[[] for i in range(numRows)]

        # for i in range(strlen):
        #     res=i%(2*numRows-2)
        #     group=i//(2*numRows-2)
        #     if res<numRows:
        #         reslist[res][group*(numRows-1)]=s[i]
        #     else:
        #         bias=res-numRows+1
        #         reslist[numRows-1-bias][group*(numRows-1)+bias]=s[i]
        for i in range(strlen):
            res = i % (2 * numRows - 2)
            group=i//(2*numRows-2)
            if res<numRows:
                reslist[res].append(s[i])
            else:
                bias=res-numRows+1
                reslist[numRows-1-bias].append(s[i])

        # for i in range(numRows):
        #     for j in range(numCols):
        #         if reslist[i][j]!=0:
        #             container.append(reslist[i][j])
        ress=[]
        for i in reslist:
            ress.extend(i)
        return ''.join(ress)

s=Solution()
a=s.convert('abcdefg',3)
print(a)
