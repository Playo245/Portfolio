#!/usr/bin/env python3


class Pizza(object):

    orders = 0
    def __init__(self, ingredients=[]):
        Pizza.orders += 1
        self.ingredients = ingredients
        self.order_number = Pizza.orders

    def serrano():
        return Pizza(['Black olives', 'Red onion', 'Meatballs'])

    def diavola():
        return Pizza(["Mozzarella", "Spicy sausage", "Pomodorino tomatoes"])

    def margherita():
        return Pizza(['Red tomatoes', 'White mozzarella', 'Green basil'])


p1 = Pizza(['Black olives', 'Red onion', 'Meatballs'])
p2 = Pizza.diavola()
p3 = Pizza.margherita()
p4 = Pizza.serrano()
print(p1.ingredients)
print(p2.ingredients)
print(p3.ingredients)
print(p4.ingredients)
print(p1.order_number)
print(p2.order_number)
print(p4.order_number)
print(p3.order_number)
