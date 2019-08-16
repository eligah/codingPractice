from leetcode import ListNode

class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        ls=[]
        p=head
        while p:
            ls.append(p.val)
            p=p.next
        if val in ls:
            ls.remove(val)
        return createlist(ls)

def createlist(data):
    if not data:
        return None
    if len(data) == 1:
        return ListNode(data[0])
    h = ListNode(data[0])
    p = h
    for item in data[1:]:
        p.next = ListNode(item)
        p = p.next
    return h
