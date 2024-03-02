from django.urls import path
from .views import *

urlpatterns = [
    path('', view_homepage),
    path('createpizza', create_pizza, name='create_pizza'),
    path('createpizza/<int:id>', create_pizza, name='create_pizza_id'),
    path('createpizza/<int:id>/details', delivery_details, name='delivery_details'),
    path('contact', contact_view, name='contact'),
]
