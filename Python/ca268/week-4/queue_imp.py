

class Queue:

    def __init__(self):
        self.items = []

    def is_empty(self):
        return self.items == []

    def enqueue(self, item):
        self.items.insert(0, item)

    def dequeue(self):
        return self.items.pop()

    def size(self):
        return len(self.items)

    def reverse(self):
        c = 0
        for i in self.items:
            self.items.insert(c, self.items[-1])
            self.items.pop()
            c += 1

    def sort(self, n = 0):
        if n < len(self.items):
            return self.items
        return s

if __name__ == "__main__":
    q = Queue()
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)
    q.reverse()
    q.sort()
    #print(q.dequeue())
    #print(q.size())
    #print(q.dequeue())
    #print(q.dequeue())
    #print(q.is_empty())
    #print(q.size())

