#!/usr/bin/env python3


class Person(object):

    def __init__(self, fname, lname, age):
        self.fname = fname
        self.lname = lname
        self.age = age


def sort_person(list, atribute):

    sort_list=[]
    if atribute == "fname":
        for i in list:
            sort_list.append(i.fname)

    elif atribute == "lname":
        for i in list:
            sort_list.append(i.lname)

    else:
        for i in list:
            sort_list.append(i.age)

    sort_list.sort()
    return sort_list


p1 = Person('Barack', 'Obama', 40)
p2 = Person('Abraham', 'Lincoln', 21)
p3 = Person('Donald', 'Trump', 14)

print(sort_person([p1, p2, p3], 'fname'))
print(sort_person([p1, p2, p3], 'lname'))
print(sort_person([p1, p2, p3], 'age'))
#Im not sure if this is the output you are looking for
