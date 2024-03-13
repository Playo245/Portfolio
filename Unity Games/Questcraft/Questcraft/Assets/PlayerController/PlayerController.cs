using System.Collections;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
   //Unity, LayerMask used for raycasting
   public LayerMask layerMask;
   public GameObject handHolder;


   public InventoryManager inventory;
   public ItemClass selectedItem;
   public bool inventoryShowing = false;
   public Vector2Int mousePos;
   

   public int playerRange;
   public float moveSpeed;
   public float jumpForce;
   public bool onGround;
   //Players animation and physics from Unity
   private Rigidbody2D rb;
   private Animator anim;
   private float horizontal;
   public bool hit;
   public bool place;

   [HideInInspector]
   public Vector2 spawnPosition;
   public GenerateTerrain terrainGenerator;
   //Refrences to components and scripts
   private void Start()
   {
      rb = GetComponent<Rigidbody2D>();
      anim = GetComponent<Animator>();
      inventory = GetComponent<InventoryManager>();
   }
   //Sets Camera
   public void Spawn()
   {
      GetComponent<Transform>().position = spawnPosition;
   }

   //Movement
   private void FixedUpdate()
   {

      float jump = Input.GetAxisRaw("Jump");
      float vertical = Input.GetAxisRaw("Vertical");
      
      Vector2 movement = new Vector2(horizontal * moveSpeed, rb.velocity.y);

      if(horizontal > 0)
         transform.localScale = new Vector3(-1, 1, 1);
      else if(horizontal < 0)
         transform.localScale = new Vector3(1, 1, 1);


      if (vertical > 0.1f || jump > 0.1f)
      {
         if(onGround)
            movement.y = jumpForce;
      }
      //Additional jump force if an obstacle is above and if player is moving
      if (FootRaycast() && !HeadRaycast() && movement.x != 0)
      {
         if(onGround)
            movement.y = jumpForce * 0.7f;
      }

      rb.velocity = movement;
   }

   //Inventory + HotBar
   private void Update()
   {
      selectedItem = inventory.GetCurrentItem();
      horizontal = Input.GetAxis("Horizontal");

      if (!inventoryShowing)
      {
         hit = Input.GetMouseButton(0);
         place = Input.GetMouseButton(1);
      }


      // Handle input to interact with inventory
      if (Input.GetKeyDown(KeyCode.I))
      {
         // Toggle inventory visibility
         inventory.ToggleInventory();
         inventoryShowing = !inventoryShowing;
      }

      if (!inventoryShowing)
      {
         if(Input.GetAxis("Mouse ScrollWheel") > 0)
         {  
            inventory.UpdateCurrentSlotIndex(true);
         }
         else if(Input.GetAxis("Mouse ScrollWheel") < 0)
         {
            inventory.UpdateCurrentSlotIndex(false);
         }
      }
      
      //Sets sprite and scale of hand holder based on selected item
      if (selectedItem != null)
      {
         handHolder.GetComponent<SpriteRenderer>().sprite = selectedItem.itemIcon[0];

         if (selectedItem is TilesClass)
         {
            handHolder.transform.localScale = new Vector3(-0.5f, 0.5f, 0.5f);
         }
         else
            handHolder.transform.localScale = new Vector3(1, 1, 1);
      }
      else
         handHolder.GetComponent<SpriteRenderer>().sprite = null;

      //Place tile if within range 
      if (Vector2.Distance(transform.position, mousePos) <= playerRange &&
         Vector2.Distance(transform.position, mousePos) > 1f)
      {
         if (place)
         {
            if (selectedItem != null)
            {
               Debug.Log("Hellos");
               if (selectedItem is TilesClass)
               {  
                  if (terrainGenerator.CheckTile(selectedItem, mousePos.x, mousePos.y, false))
                  {
                     inventory.UseSelected();
                  }
               }
            }
         }
      }
 
      if (Vector2.Distance(transform.position, mousePos) <= playerRange)
      {
         if (hit)
            terrainGenerator.BreakTile(mousePos.x, mousePos.y, selectedItem);
      } 
      //Updates mouse position in world coordinates
      mousePos.x = Mathf.RoundToInt(Camera.main.ScreenToWorldPoint(Input.mousePosition).x - 0.5f);
      mousePos.y = Mathf.RoundToInt(Camera.main.ScreenToWorldPoint(Input.mousePosition).y - 0.5f);

      anim.SetFloat("horizontal", horizontal);
      anim.SetBool("hit", hit || place);
   }
   //Raycast checks for obstacles above and below player
   public bool FootRaycast()
   {
      //Calculates starting point, half of player height downwards. 
      RaycastHit2D hit = Physics2D.Raycast(transform.position - (Vector3.up * 0.5f), -Vector2.right * transform.localScale.x, 0.8f, layerMask);
      return hit;
   }

   public bool HeadRaycast()
   {
      RaycastHit2D hit = Physics2D.Raycast(transform.position + (Vector3.up * 0.5f), -Vector2.right * transform.localScale.x, 0.8f, layerMask);
      return hit;
   }
}