#!/usr/bin/env python3

guests = {
    'Randy': 'Germany',
    'Karla': 'France',
    'Wendy': 'Japan',
    'Norman': 'England',
    'Sam': 'Argentina'
}

def greetings(name):
    p = 0
    for k, v in guests.items():
        if name == k:
            return "Hi, I'm {} and I'm from {}".format(name, v)
            p = 1
    if p == 0:
        return "Hi, I'm {}".format(name)

print(greetings("Randy"))
