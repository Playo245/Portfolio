using System.Collections;
using UnityEngine;

[CreateAssetMenu(fileName = "New Tool Class", menuName = "Item/Consumable")]
public class ConsumableClass : ItemClass
{
   [Header("Consumable")]
   public float healthAdded;

   public override void Use(PlayerController caller)
   {
      base.Use(caller);
      Debug.Log("Eat Consumable");
      caller.inventory.UseSelected();
   }

   public ConsumableClass GetConsumable() { return this; }

}