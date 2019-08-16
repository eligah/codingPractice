# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
from list import printlist,createlist,ListNode
class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        if not(headA and headB):
            return None
        pA,pB=headA,headB
        while pA.next:
            pA=pA.next
        while pB.next:
            pB=pB.next
        if pA!=pB:
            return None

        pA,pB=headA,headB
        while pA != pB:
            pA=pA and pA.next or headB
            pB=pB and pB.next or headA
        return pA

nod2=ListNode(3)
nod1=ListNode(2)

s=Solution()
print(s.getIntersectionNode(nod1,nod2))