#!/usr/bin/env python3


def filter_star(dic, num):
    string = num * "*"
    sum = 0
    ndic = {}
    for k, v in dic.items():
        if v == string:
            ndic[k] = v
            sum += 1
    if sum > 0:
        print(ndic)
    else:
        print("No result found!")

filter_star({
  'Luxury Chocolates': '*****',
  'Tasty Chocolates': '****',
  'Big Chocolates': '*****',
  'Generic Chocolates': '***'
}, 2)
