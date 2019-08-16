from leetcode import ListNode
def createlist(data):

    h=ListNode(data[0])
    p=h
    for item in data[1:]:
        p.next=ListNode(item)
        p=p.next
    return h

def printlist(head):
    ls=[]
    while head:
        ls.append(head.val)
        head=head.next
    print(ls)
