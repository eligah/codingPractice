from collections import Counter
class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        c=Counter(nums)
        for i in c:
            if c[i]<2:
                continue
            else:
                base=nums.index(i)
                counter=1
                while counter<c[i]:
                    nextitem=nums.index(i,base+1)
                    if nextitem-base<=k:
                        return  True
                    base=nextitem
                    counter+=1
        return False
