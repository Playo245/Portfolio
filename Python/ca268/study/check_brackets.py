#!/usr/bin/env python3

def check_brackets(string):
    count = -1
    list = []
    bkt = "()"
    for i in string:
        if i in bkt:
            list.append(i)
    length = len(list)
    if length % 2 == 1:
        return False
    else:
        for j in range(0, length // 2):
            if list[j] == "(" and list[count] == ")":
                continue
            else:
                return False
    return True

print(check_brackets("()"))
print(check_brackets(")("))
print(check_brackets("hello(goo(d)bye)"))
print(check_brackets("hello(goo(d)bye)"))
print(check_brackets("dh(e(l))))od"))
print(check_brackets("(d(h((e(l)l))od"))
