class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.minstack=[]
        self.minpos=None


    def push(self, x):
        if not self.minstack:
            self.minpos=0
        else:
            if self.minstack[self.minpos]>x:
                self.minpos=len(self.minstack)
        self.minstack.append(x)


    def pop(self):
        """
        :rtype: void
        """
        if self.minpos!=len(self.minstack)-1:
            self.minstack.pop()
        else:
            self.minstack.pop()
            if self.minstack:
                self.minpos=self.minstack.index(min(self.minstack))
            else:
                self.minpos=None

    def top(self):
        if  self.minpos is None:
            return None
        return self.minstack[-1]


    def getMin(self):
        if self.minpos is None:
            return None
        return self.minstack[self.minpos]

    def print(self):
        print(self.minstack)

s=MinStack()
s.push(-2)
s.push(0)
s.push(-3)
print(s.getMin())
print(s.top())
s.pop()
print(s.top())
print(s.getMin())