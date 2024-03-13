using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(fileName = "tileTypes", menuName = "Tile types")]
public class TileTypes : ScriptableObject
{
   [Header("Environmet")]
   public TilesClass grass;
   public TilesClass dirt;
   public TilesClass stone;
   public TilesClass log;
   public TilesClass leaf;
   public TilesClass tallGrass;
   public TilesClass snow;
   public TilesClass sand;
   public TilesClass bedrock;

   [Header("Ores")]
   public TilesClass coal;
   public TilesClass iron;
   public TilesClass gold;
   public TilesClass diamond;
}
