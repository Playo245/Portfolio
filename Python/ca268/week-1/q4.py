#!/usr/bin/env python3


class Smoothie(object):

    def __init__(self, ingredient=[]):
        self.ingredient = ingredient
        self.types = {"Banana": .50,
            "Strawberries": 1.50,
            "Mango": 2.50,
            "Blueberries": 1.00,
            "Raspberries": 1.00,
            "Apple": 1.75,
            "Pineapple": 3.50
        }

    def get_cost(self):
        sum = 0
        for k, v in self.types.items():
            if k in self.ingredient:
                sum += v
        return "€{:.2f}".format(sum)

    def get_price(self):
        sum = self.get_cost().split("€")
        sum = float(sum[1]) + 2.5
        return "€{:.2f}".format(sum)

    def get_name(self):
        if len(self.ingredient) == 1:
            return "{} Smoothie".format(self.ingredient[0])
        else:
            return "{} Fustion".format(" ".join(self.ingredient))


drink = Smoothie(['Banana', "Blueberries", "Mango"])
print(drink.get_cost())
print(drink.get_price())
print(drink.get_name())
