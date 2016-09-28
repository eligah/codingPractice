class Solution(object):
    def maxDepth(self, root):
        if root is None:
            return 0
        nextnode=None
        depth=1
        if root.left==None and root.right==None:
            return 1
        if root.left!=None:
            depth+= self.maxDepth(root.left)
        if root.right!=None:
            if depth<self.maxDepth(root.right):
                depth+=self.maxDepth(root.right)
        return depth



s=Solution()
print(s.twoSum([0,0],0))