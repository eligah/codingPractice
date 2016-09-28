from leetcode import TreeNode
class Solution(object):
    def treverse(self, root):
        if root is not None:
            for i in self.treverse(root.left):
                yield i
            for i in self.treverse(root.right):
                yield i
            yield root.val

    def postorderTraversal(self,root):
        return list(self.treverse(root))

def createTree():
    nd3 = TreeNode(8)
    nd3.left = TreeNode(5)
    nd3.right = TreeNode(12)
    nd9 = nd3.left
    nd9.left = TreeNode(3)
    nd9.right = None
    nd20 = nd3.right
    nd20.left = TreeNode(11)
    nd20.right = TreeNode(13)
    return nd3


root = createTree()
s = Solution()
a = s.postorderTraversal(root)
print(a)

