class Stack:

    def __init__(self):
        self.items = []

    def is_empty(self):
        return self.items == []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def top(self):
        return self.items[len(self.items) - 1]

    def size(self):
        return len(self.items)

q = Stack()
list = []
string = 'EAS*Y*QUE***ST***IO*N***'
for c in string:
    if c != "*":
        q.push(c)
    else:
        list.append(q.pop())

print(list)
