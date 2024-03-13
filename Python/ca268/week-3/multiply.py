#!/usr/bin/env python3


def multiply(val1, val2):

    if val2 == 1:
        return val1

    return val1 + multiply(val1, val2 - 1)


print(multiply(5, 6))
