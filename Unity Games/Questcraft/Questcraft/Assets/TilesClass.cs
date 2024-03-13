using System.Collections;
using UnityEngine;

[CreateAssetMenu(fileName = "New Tiles Class", menuName = "Item/Tile")]
public class TilesClass : ItemClass
{
    public TilesClass wallVariant;
    public int level;
    public bool inBackground = false;
    public ItemClass tileDrop;
    public ToolClass.ToolType toolToBreak;
    public bool naturallyPlaced = true;

    public static TilesClass CreateInstance(TilesClass tile, bool isNaturallyPlaced)
    {
        var thisTile = ScriptableObject.CreateInstance<TilesClass>();
        thisTile.Init(tile, isNaturallyPlaced);
        return thisTile;
    }

    public void Init(TilesClass tile, bool isNaturallyPlaced)
    {
        itemName = tile.itemName;
        itemIcon = tile.itemIcon;
        wallVariant = tile.wallVariant;
        inBackground = tile.inBackground;
        tileDrop = tile.tileDrop;
        naturallyPlaced = isNaturallyPlaced;
        toolToBreak = tile.toolToBreak;
    }
    

    public override void Use(PlayerController caller)
    {
        // Add specific behavior for using a tile
        Debug.Log("Place");
    }
    public TilesClass GetTile() { return this; }
}
