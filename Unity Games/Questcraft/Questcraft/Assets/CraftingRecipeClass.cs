using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(fileName = "newCraftingRecipe", menuName = "Crafting/Recipe")]
public class CraftingRecipeClass : ScriptableObject
{
    [Header("Crafting Recipe")]
    public SlotClass[] inputItems;
    public SlotClass outputItem;

    public bool canCraft(InventoryManager inventory)
    {
        //Check if there is space in inventory
        if (inventory.isFull(outputItem.item, outputItem.quantity))
            return false;
        
        for (int i = 0; i < inputItems.Length; i++)
        {
            if (!inventory.Contains(inputItems[i].item, inputItems[i].quantity))
                return false;
        }
        //All required items are present
        return true;
    }
    //Remove crafting componenets, add crafted item
    public void Craft(InventoryManager inventory)
    {
        for (int i = 0; i < inputItems.Length; i++)
        {
            inventory.Remove(inputItems[i].item, inputItems[i].quantity);
        }

        inventory.Add(outputItem.item, outputItem.quantity);
    }
}
