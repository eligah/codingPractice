from leetcode import TreeNode


class Solution(object):
    def __init__(self):
        self.cnt = 0

    def kthSmallest(self, root, k):
        if not root:
            return None
        nodelist = [root]
        cur = nodelist[-1]
        cnt = 0
        haveseen = set()
        while nodelist:
            if cur.left and not cur.left in haveseen:
                nodelist.append(cur.left)
            else:
                res = nodelist.pop()
                haveseen.add(res)
                cnt += 1
                if cnt == k:
                    return res.val
                if cur.right:
                    nodelist.append(cur.right)
            cur = nodelist[-1]

    def kthSmallest2(self, root, k):
        if not root:
            return None
        res = self.kthSmallest2(root.left, k)
        if self.cnt == k:
            return res
        else:
            self.cnt+=1
            if self.cnt==k:
                return root
        return  self.kthSmallest2(root.right, k)


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
a = s.kthSmallest(root, 3)
print(a)
