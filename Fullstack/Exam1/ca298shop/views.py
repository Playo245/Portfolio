from django.shortcuts import render, get_object_or_404
from django.http import HttpResponse, HttpResponseRedirect
from .models import *
from .forms import *

# Create your views here.
def index(request):
    all_clothes = Clothes.objects.all()
    return render(request, 'index.html', {'clothes':all_clothes})

def view_single_clothing(request, clothesid):
    single_clothing = get_object_or_404(Clothes, id=clothesid)
    return render(request, 'cloth.html', {'clothes':single_clothing})

def add_cloth(request):
    if request.method == "POST":
        form = Clothesform(request.POST)
        if form.is_valid():
            emp = form.save()
            return render(request, 'created.html', {'emp':emp})
        else:
            return render(request, 'create_emp.html', {'form': form})
    else:
        form = Clothesform()
        return render(request, 'create_emp.html', {'form': form})

def contact_view(request):
    if request.method == 'POST':
        name = request.POST.get('name')
        email = request.POST.get('email')
        message = request.POST.get('message')
        return HttpResponse('Message sent!')
    return render(request, 'contact.html')
