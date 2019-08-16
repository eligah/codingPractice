# 1.list -元组转化list
# 2.join函数-将字符串使用列表连接
def reverse(s):
    llist=list(s)
    llist.reverse()
    s="".join(llist)
    return s
