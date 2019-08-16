from leetcode import TreeNode
class Solution(object):
    def hasPathSum(self, root, sum):
        if not root:
            return False
        if root.val==sum and root.left==None and root.right==None:
            return True
        else:
            return self.hasPathSum(root.left,sum-root.val) or \
                    self.hasPathSum(root.right,sum-root.val)
