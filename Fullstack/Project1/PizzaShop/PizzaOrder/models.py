from django.db import models

class Pizza(models.Model):
    id = models.AutoField(primary_key=True)
    size = (
        ('xsmall', 'Xtra Small (6")'),
        ('small', 'Small (9")'),
        ('medium', 'Medium (12")'),
        ('large', 'Large (15")'),
        ('xlarge', 'Xtra Large(19")'),
        ('xxlarge', 'Mega Xtra Large(21")'))
    size = models.CharField(max_length=20, choices=size, default='xsmall')
    crust = (
        ('normal', 'Normal'),
        ('thin', 'Thin'),
        ('thick', 'Thick'),
        ('chunky', 'Extra-Thick'),
        ('glutenfree', 'Gluten-Free'))
    crust = models.CharField(max_length=20, choices=crust, default='normal')
    sauce = (
        ('Tomato Sauce', 'Tomato Sauce'),
        ('BBQ Sauce', 'BBQ Sauce'),
        ('Peri Peri Sauce', 'Peri-Peri Sauce')
    )
    sauce = models.CharField(max_length=20, choices=sauce, default='Tomato Sauce')
    cheese = (
        ('Mozzarella', 'Mozzarella'),
        ('Vegan', 'Vegan'),
        ('Low fat', 'Low fat'),
        ('Cheddar', 'Cheddar'),
        ('Organic Cheese', 'Organic Cheese'),
    )
    cheese = models.CharField(max_length=25, choices=cheese, default='Mozzarella')
    # Topping for pizza
    Pepperoni = models.BooleanField(default=False)
    Chicken = models.BooleanField(default=False)
    Ham = models.BooleanField(default=False)
    Pineapple = models.BooleanField(default=False)
    Peppers = models.BooleanField(default=False)
    Mushrooms = models.BooleanField(default=False)
    Onions = models.BooleanField(default=False)
    Extra_Cheese = models.BooleanField(default=False)

    toppings = []
    if Pepperoni == True:
        toppings.append("Pepperoni")
    if Peppers == True:
        toppings.append("Peppers")
    if Ham == True:
       toppings.append("Ham")
    if Chicken == True:
        toppings.append("Chicken")
    if Pineapple == True:
        toppings.append("Pineapple")
    if Mushrooms == True:
        toppings.append("Mushrooms")
    if Onions == True:
        toppings.append("Onions")
    if Extra_Cheese == True:
        toppings.apppend("Extra Cheese")
 
    def __str__(self):
        toppings = []
        if self.Pepperoni == True:
            toppings.append("Pepperoni")
        if self.Pineapple == True:
            toppings.append("Pineapple")
        if self.Peppers == True:
            toppings.append("Pepper")
        if self.Chicken == True:
            toppings.append("Chicken")
        if self.Ham == True:
            toppings.append("Ham")
        if self.Mushroom == True:
            toppings.append("Mushroom")
        if self.Onion == True:
            toppings.append("Onion")
        if self.Extra_Cheese == True:
            toppings.append("Extra Cheese")
        
        return str(" ".join(toppings))

    def __str__(self):
        return self.size

class PizzaSauce(models.Model):
    id = models.AutoField(primary_key=True)
    sauce = models.TextField(default='')

    def __str__(self):
        return self.sauce

class PizzaCrust(models.Model):
    id = models.AutoField(primary_key=True)
    crust = models.TextField(default='')

    def __str__(self):
        return self.crust

class PizzaCheese(models.Model):
    id = models.AutoField(primary_key=True)
    cheese = models.TextField(default='')

    def __str__(self):
        return self.cheese

class PizzaOrder(models.Model):
    id = models.AutoField(primary_key=True)
    crust = models.ForeignKey(PizzaCrust, on_delete=models.SET_NULL, null=True)
    size = models.ForeignKey(Pizza, on_delete=models.SET_NULL, null=True)
    cheese = models.ForeignKey(PizzaCheese, on_delete=models.SET_NULL, null=True)
    sauce = models.ForeignKey(PizzaSauce, on_delete=models.SET_NULL, null=True)

class DeliveryDetail(models.Model):
    id = models.AutoField(primary_key=True)
    first_name = models.CharField(max_length=20)
    last_name = models.CharField(max_length=20)
    address1 = models.CharField(max_length=50, default='')
    address2 = models.CharField(max_length=50, default='')
    city = models.CharField(max_length=30, default='')
    county = models.CharField(max_length=30, default='')
    eircode = models.CharField(max_length=7, default='')
    card = models.IntegerField()
    cvv = models.CharField(max_length=3)
    expiry = models.CharField(max_length=5)
    pizza_order = models.ForeignKey(PizzaOrder, on_delete=models.SET_NULL, null=True)

    def __str__(self):
        return "{}, {}, {}, {}, {}, {}, {}, {}, {}".format(self.first_name, self.last_name, self.address1, self.county, self.eircode, self.card, self.expiry, self.cvv, self.id)