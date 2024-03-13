using System.Collections;
using UnityEngine;

[CreateAssetMenu(fileName = "New Tool Class", menuName = "Item/Tool")]
public class ToolClass : ItemClass
{
   [Header("Tool")]
   public ToolType toolType;
   public int level;
   public float TimeToBreak;

   public enum ToolType
   {
      weapon,
      pickaxe,
      hammer,
      axe,
      unbreakable
   }

   public override void Use(PlayerController caller)
   {
      base.Use(caller);
      Debug.Log("Swing tool");
   }

   public ToolClass GetTool() { return this; }
} 
