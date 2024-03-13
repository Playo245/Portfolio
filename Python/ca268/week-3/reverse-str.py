#!/usr/bin/env python3


def reverse_str(string):

    if len(string) == 0:
        return string

    return string[-1] + reverse_str(string[:-1])


print(reverse_str("hello"))
