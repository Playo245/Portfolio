#!/usr/bin/env python3


def sum(num):

    if num == 0:
        return 0

    return num + sum(num - 1)


print(sum(3))
