class Queue(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.pusher=[]
        self.poper=[]
        

    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        self.pusher.append(x)
        

    def pop(self):
        """
        :rtype: nothing
        """
        if not self.poper:
            while self.pusher:
                self.poper.append(self.pusher.pop())
        self.poper.pop()

    def peek(self):
        """
        :rtype: int
        """
        if not self.poper:
            return self.pusher[0]
        return self.poper[-1]
        

    def empty(self):
        """
        :rtype: bool
        """
        if not self.poper:
            if not self.pusher:
                return True
        return False


s=Queue()
s.push(1)
s.push(2)
s.push(3)
print(s.peek())
s.pop()
print(s.peek())
s.pop()
print(s.peek())
s.pop()
