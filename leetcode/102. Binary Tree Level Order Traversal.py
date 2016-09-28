class Solution(object):
    def levelOrder(self, root):
        if not root:
            return []
        res=[]
        nodequeue1=[]
        res.append([root.val])
        nodequeue1.append(root)
        nodequeue2=[]
        while nodequeue1 or nodequeue2:
            while  nodequeue1:
                currnode=nodequeue1.pop(0)
                if  currnode.left:
                    nodequeue2.append(currnode.left)
                if  currnode.right:
                    nodequeue2.append(currnode.right)
            res.append([node.val for node in nodequeue2 if node])
            nodequeue1=nodequeue2[:]
            nodequeue2=[]
        res.pop()
        return res
