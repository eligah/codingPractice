# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None
from copy import deepcopy,copy
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return None
        if not head.next:
            return head
        ll=[]
        while not head:
            ll.append(head.val)
            head=head.next
        ll.reverse()
        hh=ListNode(ll[0])
        p=hh
        for item in ll[1:]:
            p.next=ListNode(item)
            p=p.next
        return hh





s=Solution()

print(l)

