# Definition for singly-linked list.

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def detectCycle(self, head):
        if not head:
            return None
        p=head
        idContainer={}
        while p:
            if str(id(p)) in idContainer:
                return p
            else:
                idContainer[str(id(p))]=1
                p=p.next
        return None

nod=ListNode(1)
nod.next=nod

s=Solution()
print(s.detectCycle(nod))