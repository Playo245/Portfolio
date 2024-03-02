from django import forms
from django.forms import ModelForm, ModelChoiceField
from django.db import transaction
from .models import *

class Clothesform(forms.ModelForm):
    
    class Meta:
        model = Clothes
        fields = ['name', 'description', 'size', 'type', 'price', 'colour', 'stock']
    
    def clean(self):
        data = self.cleaned_data
        name = data['name']
        description = data['description']
        size = data['size']
        type = data['type']
        price = data['price']
        colour = data['colour']
        stock = data['stock']
        Clothes_exists = Clothes.objects.filter(name=name).exists()
        if Clothes_exists:
            raise forms.ValidationError("This clothing is already listed on the site!")
        
        return data
