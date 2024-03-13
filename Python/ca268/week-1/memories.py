#!/usr/bin/env python3


class Memories(object):

    def __init__(self, name="", age=0, salary=0):
        self.name = name
        self.age = age
        self.salary = salary
        self.info = {"name" : name, "age" : age, "salary" : salary}

    def remember(self, sum):
        if sum in self.info:
            return self.info[sum]
        else:
            return False

person1 = Memories(name="Tom", age=32, salary=50000)
print(person1.remember("salary"))
print(person1.remember("email"))
