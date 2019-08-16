from heapq import heappop,heappush

class Solution(object):
    def nthUglyNumber(self,n):
        h=[1]
        i=0
        s=set()
        while i<n:
            e=heappop(h)
            if e not in h:
                s.add(e)
                heappush(h,e*2)
                heappush(h,e*3)
                heappush(h,e*5)
                i+=1
        return e