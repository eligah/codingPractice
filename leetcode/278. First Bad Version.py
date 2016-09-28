def isBadVersion(version):
    return False if  version<2 else True

class Solution(object):
    def firstBadVersion(self, n):
        l,r=0,n-1
        piovt=1
        while l<=r:
            mid=(l+r)//2
            piovt=mid+1
            if isBadVersion(piovt):
                if not isBadVersion(piovt-1):
                    break
                r=mid-1
            else:
                l=mid+1
        return piovt

s=Solution()
a=s.firstBadVersion(1)
print(a)
        