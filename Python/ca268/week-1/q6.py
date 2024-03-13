#!/usr/bin/env python3


class Employee(object):

    def __init__(self, name, **kwargs):
        name = name.split()
        self.firstname = name[0]
        self.lastname = name[1]
        for k, v in kwargs.items():
            self.__dict__[k] = v

tom = Employee('Tom Ford')
john = Employee('John Travolta', nationality='American')
jack = Employee('Jack Nicholson', nationality='American', age=84)

print(jack.age)
print(jack.nationality)
print(tom.firstname)
print(john.lastname)
