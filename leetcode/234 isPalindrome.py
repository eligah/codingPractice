from operator import eq
class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        p=head
        ll=[]
        while p:
            ll.append(p.val)
            p=p.next
        lr=ll[:]
        ll.reverse()
        return eq(lr,ll)

