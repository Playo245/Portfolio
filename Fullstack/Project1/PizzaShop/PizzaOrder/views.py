from django.shortcuts import render, get_object_or_404
from django.http import HttpResponse, HttpResponseRedirect
from .models import  Pizza
from .forms import *

# Create your views here.
def view_homepage(request):
    return render(request, 'homepage.html')

def create_pizza(request):
    if request.method == "POST":
        form = PizzaForm(request.POST)
        if form.is_valid():
            pizza = form.save()
            return HttpResponseRedirect('createpizza/' + str(pizza.id) + '/details', {'pizza':pizza})
        else:
            return render(request, 'create_pizza.html', {'form':form})
    else:
        form = PizzaForm()
        return render(request, 'create_pizza.html', {'form':form,})

def delivery_details(request, id):
    if request.method == "POST":
        form = DetailsForm(request.POST)
        if form.is_valid():
            details = form.save()
            customer = get_object_or_404(DeliveryDetail, id=id)
            pizza = get_object_or_404(Pizza, id=id)
            return render(request, 'confirmation.html', {'pizza':pizza, 'customer':customer, 'details':details})
        else:
            return render(request, 'details.html', {'form':form})
    else:
        form = DetailsForm()
        return render(request, 'details.html', {'form':form})
    
def contact_view(request):
    if request.method == 'POST':
        name = request.POST.get('name')
        email = request.POST.get('email')
        message = request.POST.get('message')
        return HttpResponse('Message sent!')
    return render(request, 'contact.html')