class Solution(object):
    def computeArea(self, A, B, C, D, E, F, G, H):
        if A>C:
            A,B,C,D,E,F,G,H=E,F,G,H,A,B,C,D
        def caculatearea(A,B,C,D):
            return (C-A)*(D-B)
        def getintersaction(r1,r2):
            l=max(r1[0],r2[0])
            r=min(r1[1],r2[1])
            return [l,r] if l<r else [0,0]
        s1=caculatearea(A,B,C,D)
        s2=caculatearea(E,F,G,H)
        inter=0
        l_inter=getintersaction([A,C],[E,G])
        h_inter=getintersaction([B,D],[F,H])
        s_inter=(h_inter[1]-h_inter[0])*(l_inter[1]-l_inter[0])
        return s1+s2-s_inter

s=Solution()
a=s.computeArea(-2,-2,2,2,-2,-2,2,2)
print(a)