# Generated by Django 4.1.7 on 2023-03-01 17:19

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('PizzaOrder', '0003_pizza_remove_pizzaorder_chicken_and_more'),
    ]

    operations = [
        migrations.AddField(
            model_name='pizza',
            name='cheese',
            field=models.CharField(choices=[('Mozzarella', 'Mozzarella'), ('Vegan', 'Vegan'), ('Low fat', 'Low fat'), ('Cheddar', 'Cheddar'), ('Organic Cheese', 'Organic Cheese')], default='Mozzarella', max_length=25),
        ),
    ]
