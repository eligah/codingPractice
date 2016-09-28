from list import createlist,printlist
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    def __str__(self):
        return self.val

class Solution(object):
    def mergeTwoLists(self, l1,l2):
        if not l1:
            return l2
        if not l2:
            return l1
        ph1,ph2=l1,l2

        ph=ListNode(min(l1.val,l2.val))
        if ph.val==l1.val:
            ph1=ph1.next
        else:
            ph2=ph2.next
        pp=ph

        while ph1 and ph2:
            if ph1.val>ph2.val:
                pp.next=ph2
                pp=pp.next
                ph2=ph2.next
            else:
                pp.next=ph1
                pp=pp.next
                ph1=ph1.next

        pp.next=ph1 and ph1 or ph2
        return ph



pl1=createlist([1])
pl2=createlist([0])
s=Solution()
w=s.mergeTwoLists([],pl2)
printlist(w)