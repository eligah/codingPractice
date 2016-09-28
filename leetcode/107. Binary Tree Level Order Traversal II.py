# Definition for a binary tree node.
from leetcode import  TreeNode

class Solution(object):
    def levelOrderBottom(self, root):
        if not root:
            return []
        res=[]
        nodequeue1=[]
        res.append([root.val])
        nodequeue1.append(root)
        nodequeue2=[]
        while nodequeue1 or nodequeue2:
            while  nodequeue1:
                currnode=nodequeue1.pop(0)
                if  currnode.left:
                    nodequeue2.append(currnode.left)
                if  currnode.right:
                    nodequeue2.append(currnode.right)
            res.append([node.val for node in nodequeue2 if node])
            nodequeue1=nodequeue2[:]
            nodequeue2=[]
        res.reverse()
        res.pop(0)
        return res


def createTree():
    nd3 = TreeNode(1)
    nd3.left = TreeNode(2)
    nd3.right = TreeNode(3)
    nd9=nd3.left
    nd9.left=TreeNode(4)
    nd9.right=None
    nd20 = nd3.right
    nd20.left = None
    nd20.right = TreeNode(5)
    return nd3


root=createTree()
s=Solution()
a=s.levelOrderBottom(root)
print(a)
