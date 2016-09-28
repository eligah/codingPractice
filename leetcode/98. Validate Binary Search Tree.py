from leetcode import  TreeNode
class Solution(object):
    def isValidBST(self, root):
        stack,rst=[],[]
        while stack or root:
            if root:
                stack.append(root)
                root=root.left
            else:
                node=stack.pop()
                if rst and node.val<=rst[-1]:
                    return False
                else:
                    rst.append(node.val)
                    root=node.right
        return True


def isValidBST(self, root):
    def helper(root, minV, maxV):
        if not root: return True
        if root.val <= minV or root.val >= maxV:
            return False
        return helper(root.left, minV, root.val) and helper(root.right, root.val, maxV)

    return helper(root, float('-inf'), float('inf'))
def createTree():
    nd3 = TreeNode(10)
    nd3.left = TreeNode(5)
    nd3.right = TreeNode(15)
    # nd15=nd3.right
    # nd15.left=TreeNode(6)
    # nd15.right=TreeNode(20)
    return nd3

if __name__=='__main__':
    s=Solution()
    a=s.isValidBST(createTree())
    print(a)