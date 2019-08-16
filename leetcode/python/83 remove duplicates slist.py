class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    def __str__(self):
        return self.val

class Solution(object):
    def deleteDuplicates(self, head):
        p=head
        while p and p.next:
            if p.val==p.next.val:
                self.deleteNode(p)
            else:
                p=p.next
        return head

    def deleteNode(self,node):
        node.val=node.next.val
        node.next=node.next.next



lhead=ListNode(1)
pl=createlist(lhead,[1,2,2])
printlist(pl)
s=Solution()
w=s.deleteDuplicates(pl)
printlist(w)