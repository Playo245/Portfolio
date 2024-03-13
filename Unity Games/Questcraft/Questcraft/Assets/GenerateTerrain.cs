using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GenerateTerrain : MonoBehaviour
{
   //Lighting Parameters, can be set in Unity and within this script
   [Header("Lighting")]
   public Texture2D worldTileMap;
   public Material lightShader;
   public float groundLightThreshold = 0.7f;
   public float airLightThreshold = 0.85f;

   public float lightThreshold;
   public float lightRadius = 7f;
   List<Vector2Int> unlitBlocks = new List<Vector2Int>();
   
   public PlayerController player;
   public CameraController cameraCtrl;
   public GameObject tileDrop;

   [Header("Tile Types")]
   public float seed;
   public BiomeClass [] biomes;
   public TileTypes tileTypes;
   
   [Header("Biomes")]
   public float biomeFrequency;
   public Gradient biomeGradient;
   public Texture2D biomeMap;

   [Header("World Generation")]
   public int chunkSize = 16;
   public bool caveGeneration = true;
   public int world = 100;
   public int heightSteep = 25;

   [Header("Noise Settings")]
   public float caveFrequency = 0.05f;
   public float terrainFrequency = 0.05f;
   public Texture2D caveNoiseTexture;

   [Header("Ore Settings")]
   public OreClass[] ores;
   //Arrays to hold world chunks and tiles, distinguishes background and foreground
   private GameObject[] worldChunks;
   private GameObject[,] worldForegroundObjects;
   private GameObject[,] worldBackgroundObjects;
   
   private TilesClass[,] worldBackgroundTiles;
   private TilesClass[,] worldForegroundTiles;
   //Current biome, The color of that biome, each biome has different colors
   private BiomeClass currBiome;
   private Color[] biomeCol;

   private void Start()
   {
      //Arrays and textures
      worldForegroundTiles = new TilesClass[world, world];
      worldBackgroundTiles = new TilesClass[world, world];
      worldForegroundObjects = new GameObject[world, world];
      worldBackgroundObjects = new GameObject[world, world];

      worldTileMap = new Texture2D(world, world);
      worldTileMap.filterMode = FilterMode.Point;
      lightShader.SetTexture("_ShadowTex", worldTileMap);
     
      for (int x = 0; x < world; x++)
      {
         for (int y = 0; y < world; y++)
         {
            worldTileMap.SetPixel(x, y, Color.white);
         }
      }

      worldTileMap.Apply();
      
      seed = Random.Range(-10000, 10000);
      for (int i = 0; i < ores.Length; i++)
      {
         ores[i].clumpTexture = new Texture2D(world, world);
      }

      biomeCol = new Color[biomes.Length];

      for (int i = 0; i < ores.Length; i++)
      {
         biomeCol[i] = biomes[i].biomeCol;
      }
       
      DrawBiomeMap();
      DrawCavesAndOres();
      CreateChunks();
      TerrainGeneration();
      //Applies lighting to unlit blocks
      for (int x = 0; x < world; x++)
      {
         for (int y = 0; y < world; y++)
         {
            if (worldTileMap.GetPixel(x, y) == Color.white)
               LightBlock(x, y, 1f, 0);
         }
      }

      worldTileMap.Apply();

      //Spawns player and set camera
      cameraCtrl.Spawn(new Vector3(player.spawnPosition.x, player.spawnPosition.y, cameraCtrl.transform.position.z));
      cameraCtrl.world = world;
      player.Spawn();
      RefreshChunks();
   }

   private void Update()
   {
      RefreshChunks();
   }

   #region Terrain Generation
   //Deactivates chunks outside of camera view, used to optimize
   void RefreshChunks()
   {
      for (int i = 0; i < worldChunks.Length; i++)
      {
         //Distance between center of each chunk and player position
         if(Vector2.Distance(new Vector2((i * chunkSize) + (chunkSize / 2), 0), new Vector2(player.transform.position.x, 0)) > Camera.main.orthographicSize * 5f)
            worldChunks[i].SetActive(false);
         else
            worldChunks[i].SetActive(true);
      }
   }
   //BiomeMap using perlin noise and gradient, generates varied terrain for biomes
   public void DrawBiomeMap()
   {
      float b;
      Color col;
      biomeMap = new Texture2D(world, world);
      //Loops through every pixel in biomeMap
      for (int x = 0; x < biomeMap.width; x++)
         {
            for (int y = 0; y < biomeMap.height; y++)
            {
               //Generate perlin noise value used to make natural looking terrain through gradient noise
               b = Mathf.PerlinNoise((x + seed) * biomeFrequency, (y + seed) * biomeFrequency);
               //Maps noise value to color based on graient
               col = biomeGradient.Evaluate(b);
               biomeMap.SetPixel(x, y, col);
            }
        }
        biomeMap.Apply();
   }
   //Gets current biome at given position based on color
   public BiomeClass GetCurrentBiome(int x, int y)
   {
      //Checks if pixel matches any of predefined biome colors
      if (System.Array.IndexOf(biomeCol, biomeMap.GetPixel(x, y)) >= 0)
         return biomes[System.Array.IndexOf(biomeCol, biomeMap.GetPixel(x, y))];

      return currBiome;
   }

   public void DrawCavesAndOres()
   {
      caveNoiseTexture = new Texture2D(world, world);
      float caveNoiseValue;
      float oreNoiseValue; 

      for (int x = 0; x < world; x++)
      {
         for(int y = 0; y < world; y++)
         {
            currBiome = GetCurrentBiome(x, y);
            caveNoiseValue = Mathf.PerlinNoise((x + seed) * caveFrequency, (y + seed) * caveFrequency);
            //Set pixel Color in cave noise texture based on generated noise value - should a particular pixel be a cave or not, underground or not
            if (caveNoiseValue > currBiome.worldSurface)
               caveNoiseTexture.SetPixel(x, y, Color.white);
            else
               caveNoiseTexture.SetPixel(x, y, Color.black);
            //Iterates over each ore type, each biome has differnt ore rarity
            for (int i = 0; i < ores.Length; i++)
            {
               //For each type of ore, calculates noise value based on position and rarity
               ores[i].clumpTexture.SetPixel(x, y, Color.black);
               if ( currBiome.ores.Length >= i + 1)
               {
                  oreNoiseValue = Mathf.PerlinNoise((x + seed) * currBiome.ores[i].rarity, (y + seed) * currBiome.ores[i].rarity);
                  //If greater htan size threshold, ore should be present
                  if (oreNoiseValue > currBiome.ores[i].size)
                     ores[i].clumpTexture.SetPixel(x, y, Color.white);
                  ores[i].clumpTexture.Apply();   
               }
             }
         }   
      }
            
      caveNoiseTexture.Apply();
   }

   public void CreateChunks()
   {
      //Number of chunks needed based on world size
      int numChunks = world / chunkSize;
      worldChunks = new GameObject[numChunks];
      for (int i = 0; i < numChunks; i++)
      {
         //Creates, names, sets parent to gameobject and stores chunk
         GameObject newChunk = new GameObject();
         newChunk.name = i.ToString();
         newChunk.transform.parent = this.transform;
         worldChunks[i] = newChunk;
      }
   }

   //Generates world, based on biome characteristics
   public void TerrainGeneration()
   {
      TilesClass tileClass;
      //Iterates over x and y coordinates
      for (int x = 0; x < world - 1; x++)
      {
         float height; 

         for (int y = 0; y < world; y++)
         {
            //Determines current biome, calculates height based on current biome parameters
            currBiome = GetCurrentBiome(x, y);
            height = Mathf.PerlinNoise((x + seed) * terrainFrequency, seed * terrainFrequency) * currBiome.heightMulti + heightSteep;
            //Sets player to center of world
            if (x == world / 2)
               player.spawnPosition = new Vector2(x, height + 2);
            
            if(y >= height) 
               break;
            //Determines tile class based on height and biome
            if (y < height - currBiome.dirtLayerTop)
            {
               //Set to stone if below dirt
               tileClass = currBiome.tileTypes.stone;
               //Checks for all 4 ore types and updates
               if (ores[0].clumpTexture.GetPixel(x, y).r > 0.5f && height - y > ores[0].maxOreHeight)
                  tileClass = tileTypes.coal;
               if (ores[1].clumpTexture.GetPixel(x, y).r > 0.5f && height - y > ores[1].maxOreHeight)
                  tileClass = tileTypes.iron;
               if (ores[2].clumpTexture.GetPixel(x, y).r > 0.5f && height - y > ores[2].maxOreHeight)
                  tileClass = tileTypes.gold;
               if (ores[3].clumpTexture.GetPixel(x, y).r > 0.5f && height - y > ores[3].maxOreHeight)
                  tileClass = tileTypes.diamond;
            }
            //Dirt if within dirt layer, grass if above
            else if (y < height - 1)
            {
               tileClass = currBiome.tileTypes.dirt;
            }
            else
            {
               tileClass = currBiome.tileTypes.grass;     
            }
            //Lowest point of world
            if (y == 0)
               tileClass = tileTypes.bedrock;
             
            if (caveGeneration && y > 0)
            {  
               //Place cave tile/wall variant based on noise as its part of cave
               if (caveNoiseTexture.GetPixel(x, y).r > 0.5f)
               {
                  PlaceTile(tileClass, x, y, true);
               }
               //Places wall variant tile if cave noise below threshold, occurs at cave edge where cave meets other tiles
               else if (tileClass.wallVariant != null)
               {
                  PlaceTile(tileClass.wallVariant, x, y, true);
               }
            }
            else
            {
               PlaceTile(tileClass, x, y, true);
            }
            //Tree, cactus and tall grass based on biome and terrain height
            if (y >= height - 1)
            {
               int t = Random.Range(0, currBiome.treeSpawn);
               if (t == 1)
               {
                  if (GetTileFromWorld(x, y))
                  {
                     if (currBiome.biomeName =="Desert")
                     {  
                        GenerateCactus(currBiome.tileTypes, Random.Range(currBiome.minTreeHeight, currBiome.maxTreeHeight), x, y + 1);
                     }
                     else
                     {
                        GenerateTree(Random.Range(currBiome.minTreeHeight, currBiome.maxTreeHeight), x, y + 1);
                     }
                  }
               }
               else
               {
                  int i = Random.Range(0, currBiome.tallGrass);
                  if (i == 1)
                  {
                     if (GetTileFromWorld(x, y))
                     {
                        if (currBiome.tileTypes.tallGrass != null)
                        {
                           PlaceTile(currBiome.tileTypes.tallGrass, x, y + 1, true);
                        }
                     }
                  }
               }
            }
         }
      }
      worldTileMap.Apply();
   }

   #endregion

   #region Place/Remove Tiles

   //Iterates over height, places vertically
   void GenerateCactus(TileTypes types, int treeHeight, int x, int y)
   {
      for (int i = 0; i < treeHeight; i++)
      {
         PlaceTile(types.log, x, y + i, true);
      }
   }

   void GenerateTree(int treeHeight, int x, int y)
   {
      for (int i = 0; i < treeHeight; i++)
      {
         PlaceTile(tileTypes.log, x, y + i, true);
      }
      //Places leaves around tree
      PlaceTile(tileTypes.leaf, x, y + treeHeight, true);
      PlaceTile(tileTypes.leaf, x, y + treeHeight + 1, true);
      PlaceTile(tileTypes.leaf, x, y + treeHeight + 2, true);

      PlaceTile(tileTypes.leaf, x - 1, y + treeHeight, true);
      PlaceTile(tileTypes.leaf, x - 1, y + treeHeight + 1, true);

      PlaceTile(tileTypes.leaf, x + 1, y + treeHeight, true);
      PlaceTile(tileTypes.leaf, x + 1, y + treeHeight + 1, true);
   }
   //Break tiles based on item
   public bool BreakTile(int x, int y, ItemClass item)
   {
      //Within world bounds
      if(GetTileFromWorld(x, y) && x >= 0 && x <= world && y >= 0 && y <= world){
         //Get the tile
         TilesClass tile = GetTileFromWorld(x, y);
         ToolClass tool = item as ToolClass;
         if (tool != null)
         {
            //Can tile be broken by certain tool
            if (tile.toolToBreak == tool.toolType && tool.level >= tile.level)
            {
               Debug.Log(tool.level);
               Debug.Log(tile.level);
               RemoveTile(x, y);
               return true;
            }
         }
      }

      return false;
   }

   public void RemoveTile(int x, int y)
   {
      if(GetTileFromWorld(x, y) && x >= 0 && x <= world && y >= 0 && y <= world)
      {
         TilesClass tile = GetTileFromWorld(x, y);
         RemoveTileFromWorld(x, y);
         //Places wall variant if tile was created during world generation and not player placed
         if (tile.wallVariant != null )
         {
            if (tile.naturallyPlaced)
            {
               PlaceTile(tile.wallVariant, x, y, true);
            }
         }
         
         if (tile.tileDrop)
         {
            //Creates new game object at break position, Quaternion.identity means it dosent rotate around, object is aligned with world
            GameObject newtileDrop = Instantiate(tileDrop, new Vector2(x, y + 0.5f), Quaternion.identity);
            //Sets sprite and dropped item retains its properties
            newtileDrop.GetComponent<SpriteRenderer>().sprite = tile.tileDrop.itemIcon[0];
            newtileDrop.GetComponent<TileDropController>().item = tile.tileDrop;
         } 
         //Update tile map, remove game object
         if (!GetTileFromWorld(x, y))
         {
            worldTileMap.SetPixel(x, y, Color.white);
            LightBlock(x, y, 1f, 0);
            worldTileMap.Apply();
         }
         Destroy(GetObjectFromWorld(x, y));
         RemoveObjectFromWorld(x, y);        
      }
   }

   public bool CheckTile(ItemClass selectedItem, int x, int y, bool isNaturallyPlaced)
   {  
      TilesClass tile = selectedItem as TilesClass;
      if (x >= 0 && x < world && y >= 0 && y < world)
      {
         if (tile.inBackground)
         {
            // Check if there's already a background tile at the target position
            if (worldBackgroundTiles[x, y] == null)
            {
                  // Check if there's any neighboring tile, if so, place the tile
                  if (GetTileFromWorld(x + 1, y) || GetTileFromWorld(x - 1, y) ||
                     GetTileFromWorld(x, y + 1) || GetTileFromWorld(x, y - 1))
                  {
                     if (!GetTileFromWorld(x, y))
                     {
                        RemoveLightSource(x, y);
                        PlaceTile(tile, x, y, isNaturallyPlaced);
                        return true;
                     }
                  }
            }
         }
         else
         {
            // Check if there's already a foreground tile at the target position
            if (worldForegroundTiles[x, y] == null)
            {
                  // Check if there's any neighboring tile, if so, place the tile
                  if (GetTileFromWorld(x + 1, y) || GetTileFromWorld(x - 1, y) ||
                     GetTileFromWorld(x, y + 1) || GetTileFromWorld(x, y - 1))
                  {
                     RemoveLightSource(x, y);
                     PlaceTile(tile, x, y, isNaturallyPlaced);
                     return true;
                  }
            }
         }
      }
      return false;
   } 


   public void PlaceTile(TilesClass tile, int x, int y, bool isNaturallyPlaced)
   {
      if (tile == null)
      {
         Debug.LogError("Tile parameter is null.");
         return;
      }

      if(x >= 0 && x <= world && y >= 0 && y <= world)
      {
         //Calculates coordinates of chunks which tile belongs to
         GameObject newTile = new GameObject();
         int chunkCoordinates = Mathf.RoundToInt(Mathf.Round(x / chunkSize) * chunkSize);
         chunkCoordinates /= chunkSize;
         //Set to position of chunk that tile belongs to
         newTile.transform.parent = worldChunks[chunkCoordinates].transform;
      
         newTile.AddComponent<SpriteRenderer>();
         //Randome icon based on pre defined
         int spriteIndex = Random.Range(0, tile.itemIcon.Length);
         newTile.GetComponent<SpriteRenderer>().sprite = tile.itemIcon[spriteIndex];
         
         worldTileMap.SetPixel(x, y, Color.black);
         //Tile properties based on if background or foreground
         if (tile.inBackground)
         {
            //Tile rendered behind other, if wall then its darker
            newTile.GetComponent<SpriteRenderer>().sortingOrder = -10;
            if (tile.name.ToLower().Contains("wall"))
            {
               newTile.GetComponent<SpriteRenderer>().color = new Color(0.6f, 0.6f, 0.6f);
            }
            else
            {
               worldTileMap.SetPixel(x, y, Color.white);
            } 
         }
         else
         { 
            //Foreground tile, given collider(height and width 1 unit) and tag properties
            newTile.GetComponent<SpriteRenderer>().sortingOrder = -5;
            newTile.AddComponent<BoxCollider2D>();
            newTile.GetComponent<BoxCollider2D>().size = Vector2.one;
            newTile.tag = "Ground";
         }

         newTile.name = tile.itemIcon[0].name;
         newTile.transform.position = new Vector2(x + 0.5f, y + 0.5f);

         TilesClass newTileClass = TilesClass.CreateInstance(tile, isNaturallyPlaced);
         newTileClass.level = tile.level;

         AddObjectToWorld(x, y, newTile, newTileClass);

         AddTileToWorld(x, y, newTileClass);
      }
   }
   //Adds tile to world grid, stored as foreground or background
   void AddTileToWorld(int x, int y, TilesClass tile)
   {
      if (tile.inBackground)
      {
         worldBackgroundTiles[x, y] = tile;
      }
      else
      {
         worldForegroundTiles[x, y] = tile;
      }
   }
   //Adds visual GameObject representing a tile to world, Stores GameObject refrence
   void AddObjectToWorld(int x, int y, GameObject tileObject, TilesClass tile)
   {
      if (tile.inBackground)
      {
         worldBackgroundObjects[x, y] = tileObject;
      }
      else
      {
         worldForegroundObjects[x, y] = tileObject;
      }
   }
   //Removes Tile 
   void RemoveTileFromWorld(int x, int y)
   {
      if (worldForegroundTiles[x, y] != null)
      {
         worldForegroundTiles[x, y] = null;
      }
      else if (worldBackgroundTiles[x, y] != null)
      {
         worldBackgroundTiles[x, y] = null;
      }
   }
   //Removes GameObject representing tile
   void RemoveObjectFromWorld(int x, int y)
   {
      if (worldForegroundObjects[x, y] != null)
      {
         worldForegroundObjects[x, y] = null;
      }
      else if (worldBackgroundObjects[x, y] != null)
      {
         worldBackgroundObjects[x, y] = null;
      }
   }
   //Retrives GameObject representing tile
   GameObject GetObjectFromWorld (int x, int y)
   {
      if (worldForegroundObjects[x, y] != null)
      {
         return worldForegroundObjects[x, y];
      }
      else if (worldBackgroundObjects[x, y] != null)
      {
         return worldBackgroundObjects[x, y];
      }
      return null;
   }
   //Retrievees tile at position
   TilesClass GetTileFromWorld(int x, int y)
   {
      if (worldForegroundTiles[x, y] != null)
      {
         return worldForegroundTiles[x, y];
      }
      else if (worldBackgroundTiles[x, y] != null)
      {
         return worldBackgroundTiles[x, y];
      }
      return null;
   }
   #endregion

   #region Lighting

   //Adjusts light intensity of tiles within a radius
   void LightBlock (int x, int y, float intensity, int iteration)
   {
      if (iteration < lightRadius)
      {
         //Sets Intensity
         worldTileMap.SetPixel(x, y, Color.white * intensity);
         //Determines light threshoold based on whether tile is on foreground or background
         float thresh = groundLightThreshold;
         if (x >= 0 && x < world && y >= 0 && y < world)
         {
            if (worldForegroundTiles[x, y])
               thresh = groundLightThreshold;
            else
               thresh = airLightThreshold;
         }
         //Iterates over surrounding tiles, calculates distance from current tile
         for (int nx = x - 1; nx < x + 2; nx++)
         {
            for (int ny = y -1; ny < y + 2; ny++)
            {
               if (nx != x || ny != y)
               {
                  //Based on distance and defined threshold - calculate light intensity for neighbouring tiles
                  float dist = Vector2.Distance(new Vector2(x, y), new Vector2(nx, ny));
                  float targetIntensity = Mathf.Pow(thresh, dist) * intensity;
                  //If current neighbouring tile has a lower light intensity compared to target
                  //Calls LightBlock for neighbour with updated parameters
                  if (worldTileMap.GetPixel(nx, ny) != null)
                  {
                     if(worldTileMap.GetPixel(nx, ny).r < targetIntensity)
                     {
                        LightBlock(nx, ny, targetIntensity, iteration + 1);
                     }
                  }
               }
            }
         }

         worldTileMap.Apply();
      }
   }

   void RemoveLightSource(int x, int y)
   {
      unlitBlocks.Clear();
      UnLightBlock(x, y, x, y);

      List<Vector2Int> toRelight = new List<Vector2Int>();
      foreach (Vector2Int block in unlitBlocks)
      {
         for (int nx = block.x - 1; nx < block.x + 2; nx++)
         {
            for (int ny = block.y - 1; ny < block.y + 2; ny++)
            {
               if (worldTileMap.GetPixel(nx, ny) != null)
               {
                  if (worldTileMap.GetPixel(nx, ny).r > worldTileMap.GetPixel(block.x, block.y).r)
                  {
                     if (!toRelight.Contains(new Vector2Int(nx, ny)))
                        toRelight.Add(new Vector2Int(nx, ny));
                  }
               }
            }
         }
      }
      foreach (Vector2Int source in toRelight)
      {
         LightBlock(source.x, source.y, worldTileMap.GetPixel(source.x, source.y).r, 0);
      }
      worldTileMap.Apply();
   }

   void UnLightBlock(int x, int y, int ix, int iy)
   {
      //Is current tile beyond specified light radius from original light source
      if (Mathf.Abs(x - ix) >= lightRadius || Mathf.Abs(y - iy) >= lightRadius || unlitBlocks.Contains(new Vector2Int(x, y)))
         return;
      //Iterates neighbouring tiles, if neighbours light intensity is less than current then spread darkness from brighter tile
      for (int nx = -1; nx < x + 2; nx++)
      {
         for (int ny = y - 1; ny < y + 2; ny++)
         {
            if (nx != x || ny != y)
            {
               if (worldTileMap.GetPixel(nx, ny) != null)
               {
                  if (worldTileMap.GetPixel(nx, ny).r < worldTileMap.GetPixel(x, y).r)
                  {
                     UnLightBlock(nx, ny, ix, iy);
                  }
               }
            }
         }
      }

      worldTileMap.SetPixel(x, y, Color.black);
      unlitBlocks.Add(new Vector2Int(x, y));
   }

   #endregion
}
