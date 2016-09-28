def countBits(num):
    """
    :type num: int
    :rtype: List[int]
    """
    tnum=num
    l=[0,]
    if num==0:
        pass
    elif num==1:
        l.append(1)
    else:
        l=[0,1]
        power=0
        while num//2 is not 0:
            num=num//2
            power+=1
        rest=tnum-2**power
        for i in range(power-1):
            l.extend([i+1 for i in l])
        for i in range(rest+1):
            l.append(l[i]+1)
    return l

print(countBits(2))
