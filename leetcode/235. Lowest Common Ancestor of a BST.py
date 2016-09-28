from leetcode import TreeNode
class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        if not root or not p or not q:
            return None
        elif p.val<root.val and q.val<root.val:
            return self.lowestCommonAncestor(root.left,p,q)
        elif p.val>root.val and q.val>root.val:
            return self.lowestCommonAncestor(root.right,p,q)
        else:
            return root