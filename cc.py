

class ee:

    def __init__(self, n):
        self.n = n

    def __iter__(self):
        return ee_iter(self.n)


class ee_iter:

    def __init__(self, n):
        self.i = b
        self.n = n

    def __iter__(self):
        return self

    def next(self):
        if self.i < self.n:
            i = self.i
            self.i += 1
            return i
        else:
            raise StopIteration
