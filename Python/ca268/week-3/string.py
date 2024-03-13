#!/usr/bin/env python3

def stringlen(string):

    if len(string) == 0:
        return 0

    return 1 + stringlen(string[:-1])

print(stringlen("Hello"))
