#!/usr/bin/env python3

def q1_sum(list):
    sum = 0
    for i in list:
        for c in i:
            if int(c) % 2 == 0:
                sum = sum + int(c)
    return sum


print(q1_sum([[1, 0, 2], [5, 5, 7], [9, 4, 3]]))
