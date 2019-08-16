class Solution(object):
    #  o(n^2)   drop it
    # def canCompleteCircuit(self, gas, cost):
    #     n=len(gas)
    #     for idx in range(n):
    #         curgas=gas[idx]
    #         step=0
    #         while step<n:
    #             curgas-=cost[(step+idx)%n]
    #             if curgas<0:
    #                 break
    #             curgas+=gas[(step+idx+1)%n]
    #             step+=1
    #         if step==n:
    #             return idx
    #     return -1

    def canCompleteCircuit(self,gas,cost):
        start=0
        count=0
        cur=0
        n=len(gas)
        while start<2*n and count<n:
            cur+=gas[start%n]-cost[start%n]
            if cur<0:
                count=0
                cur=0
            else:
                count+=1
            start+=1
        return -1 if count<n else start%n


s=Solution()
a=s.canCompleteCircuit([2,4],[3,4])
print(a)