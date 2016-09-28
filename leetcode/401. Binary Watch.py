from itertools import combinations
from functools import reduce
class Solution(object):
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        res=[]
        def gettime(bit_time):
            hour=reduce(lambda x,y:x*2+y,bit_time[:4])
            if hour>11:
                return None
            hourstr=str(hour)
            minutes=reduce(lambda x,y:x*2+y,bit_time[4:])
            if minutes>59:
                return None
            minutestr=str(minutes)
            if len(minutestr)<2:
                minutestr='0'+str(minutestr)
            return  hourstr+':'+minutestr

        bitmap=list(range(10))
        for i in combinations(bitmap,num):
            binstr = [0] * 10
            for idx in i:
                binstr[idx]=1
            timestr=gettime(binstr)
            if not timestr:
                continue
            res.append(timestr)
        return res

s=Solution()
a=s.readBinaryWatch(2)
print(a)