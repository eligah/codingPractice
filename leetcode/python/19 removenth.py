from list import createlist

class Solution(object):
    def removeNthFromEnd(self, head, n):
        if n==1 and head.next==None:
            return None
        n=n-1
        p=head
        while n>0:
            p=p.next
            n-=1

        if  p.next:
            self.deleteNode(p)
        else:
            pprev=head
            while not pprev.next == p:
                pprev.next=None
                break

        return head

    def deleteNode(self,node):
        if not node:
            return None
        node.val=node.next.val
        node.next=node.next.next

s=Solution()
a=s.removeNthFromEnd(createlist([1,2]),1)
print(a)
