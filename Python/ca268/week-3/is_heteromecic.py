#!/usr/bin/env python3


def is_heteromecic(value, n = 1):

    sum = n * (n + 1)
    if sum == value:
        return True

    elif sum > value:
        return False

    return is_heteromecic(value, n + 1)


print(is_heteromecic(110))
