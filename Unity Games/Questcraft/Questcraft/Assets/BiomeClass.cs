using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[System.Serializable]
//Sets parameters for generating biomes, Header allows us to set these in Unity itself but we can also set them heres
public class BiomeClass
{
   public string biomeName;
   public Color biomeCol;

   public TileTypes tileTypes;

   [Header("Noise Settings")]
   public Texture2D caveNoiseTexture;

   [Header("World Generation")]
   public int dirtLayerTop = 5;
   public float heightMulti = 4f;
   public float worldSurface = 0.25f;
   public bool caveGeneration = true;

   [Header("Trees")]
   public int treeSpawn = 10;
   public int minTreeHeight = 4;
   public int maxTreeHeight = 6;

   [Header("Flora")]
   public int tallGrass = 10;

   [Header("Ore Settings")]
   public OreClass[] ores;
}
