using System.Collections;
using UnityEngine;

[CreateAssetMenu(fileName = "New Tool Class", menuName = "Item/Misc")]
public class MiscClass : ItemClass
{


   public override void Use(PlayerController caller)
   {
      //base.Use(caller);
   }

   public MiscClass GetMisc() { return this; }

}