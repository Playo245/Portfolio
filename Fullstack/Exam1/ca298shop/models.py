from django.db import models

# Create your models here.
class Clothes(models.Model):
    id = models.AutoField(primary_key=True)
    name = models.CharField(max_length=20)
    description = models.TextField()
    size = (
        ('xs', 'XS'),
        ('s', 'S'),
        ('m', 'M'),
        ('l', 'L'),
        ('xl', 'XL'))
    size = models.CharField(max_length=2, choices=size, default='S')
    type = (
        ('tops', 'Tops'),
        ('bottoms', 'Bottoms'),
        ('shoes', 'Shoes'),
        ('coats', 'Coats'))
    type = models.CharField(max_length=10, choices=type, default='Tops')
    price = models.DecimalField(max_digits=6, decimal_places=2)
    colour = models.CharField(max_length=25, default='Black')
    stock = models.IntegerField(default=1)

    def __str__(self):
        return self.name