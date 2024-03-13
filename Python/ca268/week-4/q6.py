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

    def reverse(self, string):
        for c in string:
            self.push(string[-1])
            string = string[0:len(string) -1]

q = Stack()
list = []
string = 'Hello Dcu!'
q.reverse(string)

print(q.items)
