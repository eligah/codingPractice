from leetcode import TreeNode
class Solution(object):
    def sumOfLeftLeaves(self, root):
        res=0
        # 当前节点为空
        if not root:
            return 0
        # 当前为中间节点且存在左叶节点
        if root.left:
            if not (root.left.left or root.left.right):
                res+=root.left.val
        # 当前节点为中间节点
        res+=self.sumOfLeftLeaves(root.left)
        res+=self.sumOfLeftLeaves(root.right)
        return res