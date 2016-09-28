from leetcode import ListNode
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dum=ListNode(0)
        dum.next=head
        curr=dum
        while curr.next and curr.next.next:
            temp=curr.next.next
            curr.next.next=temp.next
            temp.next=curr.next
            curr.next=temp
            curr=curr.next.next
        return dum.next

