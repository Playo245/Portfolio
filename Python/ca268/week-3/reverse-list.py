#!/usr/bin/env python3


def reverse_list(list):

    if len(list) == 1:
        return [list[0]]

    return [list[-1]] + reverse_list(list[:-1])


print(reverse_list([1, 2, 3]))
