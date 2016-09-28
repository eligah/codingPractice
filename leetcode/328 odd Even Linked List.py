class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    def __str__(self):
        return self.val

class Solution(object):
    def oddEvenList(self,head):
        head2=head.next
        h1=head
        h2=head2
        while h1 and h2:
            h1.next= h2.next
            h1=h1.next
            if h1:
                h2.next=h1.next
                h2=h2.next
        tail=head
        while tail.next:
            tail=tail.next
        tail.next=head2
        return head

def createlist(head,data):
    p=head
    for item in data:
        p.next=ListNode(item)
        p=p.next
    return head

def printlist(head):
    ls=[]
    while head:
        ls.append(head.val)
        head=head.next
    print(ls)

lhead=ListNode(1)
pl=createlist(lhead,[2,3,4,5,6,7,8])
printlist(pl)
s=Solution()
s.oddEvenList(pl)
printlist(pl)

