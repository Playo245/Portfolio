using System.Collections;
using UnityEngine;


[System.Serializable]
public class SlotClass
{
    [field: SerializeField] public ItemClass item { get; private set; } = null;
    [field: SerializeField] public int quantity { get; private set; } = 0;

    public SlotClass ()
    {
        item = null;
        quantity = 0;
    }
    
    public SlotClass (SlotClass slot)
    {
        this.item = slot.item;
        this.quantity = slot.quantity;
    }

    //Sets item and quantity directly
    public SlotClass (ItemClass _item, int _quantity)
    {
        item = _item;
        quantity = _quantity;
    }


    public void Clear()
    {
        this.item = null;
        this.quantity = 0;
    }

    //Adds quantity
    public void AddQuantity(int _quantity) 
    { 
        quantity += _quantity; 
    }
    //Subtracts quantity, less than zero - clears
    public void SubQuantity(int _quantity) 
    {
        quantity -= _quantity;
        if (quantity <= 0)
            Clear();

    }
    //Adds item with specified quantity to slot
    public void AddItem(ItemClass item, int quantity)
    {
        this.item = item;
        this.quantity = quantity;
    }
}