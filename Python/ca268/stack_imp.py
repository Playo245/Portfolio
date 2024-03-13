class Stack:
    '''Python implementation the stack'''

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


s = Stack()
s.push('d')
s.push('c')
s.push('b')
n = s.pop()
m = s.pop()
l = s.pop()
s.push(n)
s.push(l)
s.push(n)
m = s.pop()
str = ''
while not s.is_empty():
    str += s.pop()
print(str, end='')
print("\n")
