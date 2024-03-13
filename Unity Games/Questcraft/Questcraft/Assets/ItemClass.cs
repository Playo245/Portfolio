using System.Collections;
using UnityEngine;

[System.Serializable]
public class ItemClass : ScriptableObject
{

   [Header("Item")]
   public string itemName;
   public Sprite[] itemIcon;
   public bool isStackable = true;
   public int stackSize = 64;

   public virtual void Use(PlayerController caller)
   {
      Debug.Log("Place");
   }
}
