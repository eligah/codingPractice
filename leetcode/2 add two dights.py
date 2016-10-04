from leetcode import ListNode
from list import printlist


class Solution(object):

    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 and l2:
            sum1 = self.getsum(l1)
            sum2 = self.getsum(l2)
            all = sum1 + sum2
            retlist = list(map(int, (str(all))))
            retlist.reverse()
            return createlist(retlist)
        else:
            return l1 and l1 or l2

    def getsum(self, l1):
        p = l1
        num = 0
        iter = 1
        while p:
            num += p.val * iter
            p = p.next
            iter *= 10
        return num


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

h1 = createlist([2, 4, 3])
h2 = createlist([5, 6, 4])
s = Solution()
ll = s.addTwoNumbers(h1, h2)
printlist(ll)
