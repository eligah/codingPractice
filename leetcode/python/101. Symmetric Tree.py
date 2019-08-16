from leetcode import TreeNode

class Solution(object):
    def isSymmetric(self, root):
        if not root:
            return []
        nodequeue1 = []
        nodequeue1.append(root)
        nodequeue2 = []
        while nodequeue1 or nodequeue2:
            while nodequeue1:
                currnode = nodequeue1.pop(0)
                if not currnode:
                    continue
                nodequeue2.append(currnode.left)
                nodequeue2.append(currnode.right)
            valist=[node.val if node else 0 for node in nodequeue2 ]
            valist2=valist[:]
            valist.reverse()
            if valist!=valist2:
                return False
            nodequeue1 = nodequeue2[:]
            nodequeue2 = []
        return True


def createTree():
    nd3 = TreeNode(1)
    nd3.left = TreeNode(2)
    nd3.right = TreeNode(2)
    nd9=nd3.left
    nd9.left=TreeNode(4)
    nd9.right=None
    nd20 = nd3.right
    nd20.left = TreeNode(4)
    nd20.right = None
    return nd3


root=createTree()
s=Solution()
a=s.isSymmetric(root)
print(a)