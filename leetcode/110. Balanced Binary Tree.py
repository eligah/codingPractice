from leetcode import  TreeNode

class Solution(object):
    def isBalanced(self,root):
        def countDepth(root):
            if not root:
                return 0
            return 1+max(countDepth(root.left),countDepth(root.right))
        if not root:
            return True
        if not self.isBalanced(root.left):
            return False
        if not self.isBalanced(root.right):
            return False
        if abs(countDepth(root.left)-countDepth(root.right))>1:
            return False
        return True

def createTree():
    nd3 = TreeNode(3)
    nd3.right = TreeNode(9)
    nd9 = nd3.right
    nd9.right=TreeNode(12)
    # nd9.left.left=TreeNode(123)
    # nd20 = nd3.right
    # nd20.left = TreeNode(11)
    # nd20.right = TreeNode(13)
    return nd3


root = createTree()
s = Solution()
a = s.isBalanced(root)
print(a)