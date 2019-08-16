from leetcode import  TreeNode
class Solution(object):
    def minDepth(self, root):
        if not root:
            return 0
        if not root.left:
            if not root.right:
                return 1
            else:
                return 1+self.minDepth(root.right)
        if  root.right:
            return 1+min(self.minDepth(root.left),self.minDepth(root.right))
        else:
            return 1+self.minDepth(root.left)


def createTree():
    nd3 = TreeNode(1)
    nd3.left = TreeNode(2)
    # nd3.right = TreeNode(3)
    # nd9=nd3.left
    # nd9.left=TreeNode(4)
    # nd9.right=None
    # nd20 = nd3.right
    # nd20.left = None
    # nd20.right = TreeNode(5)
    return nd3


if  __name__=='__main__':
    root=createTree()
    s=Solution()
    a=s.minDepth(root)
    print(a)