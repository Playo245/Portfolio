from django.urls import path
from . import views

urlpatterns = [
    path('', views.index, name="homepage"),
    path('cloth/<int:clothesid>', views.view_single_clothing, name='single_clothing'),
    path('addcloth', views.add_cloth, name='add_cloth'),
    path('contact', views.contact_view, name='contact'),
]
