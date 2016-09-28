from leetcode import  TreeNode
class Solution:
    def binaryTreePaths(self, root):
        res = []
        def treePathHelper(root,curpath):
            if not root:
                return None
            else:
                newpath=curpath[:]
                newpath.append(str(root.val))
                if  not root.left and  not root.right:
                    res.append('->'.join(newpath))
                    return
                treePathHelper(root.left,newpath)
                treePathHelper(root.right,newpath)
        treePathHelper(root,[])
        return res

def createTree():
    nd3 = TreeNode(8)
    nd3.left = TreeNode(5)
    nd3.left.left = TreeNode(4)
    nd3.left.right = TreeNode(6)
    nd3.right = TreeNode(12)
    return nd3

s=Solution()
a=s.binaryTreePaths(createTree())
print(a)



