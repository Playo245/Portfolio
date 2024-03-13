#!/usr/bin/env python3


class Person(object):

    def __init__(self, name="", age=0, height=0, weight=0):
        self.name = name
        self.age = age
        self.height = height
        self.weight = weight

    def get_age(self):
        return "{} is {} years old".format(self.name, self.age)

    def get_height(self):
        return "{} is {} cm tall".format(self.name, self.height)

    def get_weight(self):
        return "{} weighs {} kg".format(self.name, self.weight)


person1 = Person(name="Tom", age=18, height=185, weight=0)
print(person1.get_age())
print(person1.get_height())
print(person1.get_weight())
