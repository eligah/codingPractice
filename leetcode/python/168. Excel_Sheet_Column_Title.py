class Solution:
    # @return a string
    def convertToTitle(self, num):
        capatials=[chr(x) for x in range(ord('A'),ord('Z')+1)]
        result=[]
        while num:
            result.append(capatials[(num-1)%26])
            num=(num-1)//26
        result.reverse()
        return ''.join(result)


