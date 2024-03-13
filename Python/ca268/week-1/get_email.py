#!/usr/bin/env python3


class Person(object):

    def __init__(self, fname="", lname="", salary=0):
        self.fname = fname
        self.lname = lname
        self.salary = salary

    def get_email(self):
        return "{}.{}@dcu.ie".format(self.fname, self.lname)


person1 = Person(fname="Tom", lname="herry", salary=50000)
print(person1.get_email())
