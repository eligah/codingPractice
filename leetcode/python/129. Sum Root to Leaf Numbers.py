from leetcode import  TreeNode
class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def dfs(root, strs):
            if not root:
                return
            nstr= strs + str(root.val)
            if (not root.left) and (not root.right):
                res.append(int(nstr))
                return
            dfs(root.left,nstr)
            dfs(root.right,nstr)
        res=[]
        dfs(root,'')
        return sum(res)


def createTree():
    nd3 = TreeNode(1)
    # nd3.left = TreeNode(2)
    # nd3.right = TreeNode(3)
    return nd3


root=createTree()
s=Solution()
a=s.sumNumbers(root)
print(a)

