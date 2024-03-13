#!/usr/bin/env python3


def reverse_num(number):

    length = len(str(number))
    if length == 1:
        return number

    else:
        start = 10 ** length
        print(start)
        sum = start * number % 10

    return sum + reverse_num(number // 10)


print(reverse_num(123))
