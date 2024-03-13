using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;


public class InventoryManager : MonoBehaviour
{
   [SerializeField] private GameObject itemCursor;
   [SerializeField] private GameObject inventoryUI;
   [SerializeField] private GameObject craftingUI;
   [SerializeField] private GameObject ScrollBarUI;
   [SerializeField] private GameObject slotHolder;
   [SerializeField] private GameObject hotbarSlotHolder;
   [SerializeField] private SlotClass[] startingItems;

   private SlotClass[] items;
   private GameObject[] slots;
   private GameObject[] hotbarSlots;
   private SlotClass slotMoving;
   private SlotClass tempSlot;
   private SlotClass originalSlot;
   bool isItemMoving;
   bool craftingShowing = false;
   bool inventoryShowing = false;
   [SerializeField] private GameObject hotbarSelector;
   [SerializeField] private int currentSlotIndex = 0;
   public ItemClass currentItem;

   public ItemClass GetCurrentItem() => currentItem;

   private void Start()
   {
      InitialiseSlots(); // Initialise slots and items
      StartingItems(); // Add starting items to the inventory
      RefreshUI(); // Refresh the UI
   }

   private void Update()
   {
      ItemCursor(); // Update the position of the item cursor
      if (inventoryShowing)
      {  
         InputHandler(); // Handles player input if inventory is open
      }
      HotbarSelectorPosition(); // Update the position of the hotbar selector
   }

   #region Inventory Utils

   public void ToggleInventory()
   {
      inventoryUI.SetActive(!inventoryUI.activeSelf);
      inventoryShowing = !inventoryShowing;

      if (!inventoryShowing)
      {
         craftingShowing = false;
         craftingUI.SetActive(false);
         ScrollBarUI.SetActive(false);
      }
      else if (craftingShowing)
      {
         craftingUI.SetActive(true);
         ScrollBarUI.SetActive(true);
      }
   }

   public bool Add(ItemClass item, int quantity)
   {
      // Check if the inventory is full
      if (isFull(item, quantity))
      {
         return false;
      }
      
      // Check if the inventory contains the item
      SlotClass slot = Contains(item);

      if (slot != null && slot.item.isStackable && slot.quantity < item.stackSize)
      {
         // Calculate how many items can be added to the existing stack
         var quantityCanAdd = slot.item.stackSize - slot.quantity;
         // Clamp the quantity to add within the stack size limit
         var quantityToAdd = Mathf.Clamp(quantity, 0, quantityCanAdd);
            
         var remainder = quantity - quantityToAdd;
         
         // Add the quantity to the stack
         slot.AddQuantity(quantityToAdd);
         
         // If there are remaining items, recursively attempt to add them
         if (remainder > 0)
         {
            Add(item, remainder);
         }
      }
      else
      {
         for (int i = 0; i < items.Length; i++)
         {
            // If an empty slot is found
            if (items[i].item == null)
            { 
               var quantityCanAdd = item.stackSize - items[i].quantity;
               var quantityToAdd = Mathf.Clamp(quantity, 0, quantityCanAdd);
            
               var remainder = quantity - quantityToAdd;
         
               items[i].AddItem(item, quantityToAdd);
               
               if (remainder > 0) 
               {
                  Add(item, remainder);
               }
               break;
            }
         }
      }

      RefreshUI();
      return true;
   }

   public bool Remove(ItemClass item)
   {
      // Check if the item is present in the inventory
      SlotClass temp = Contains(item);
      if (temp != null)
      {
         // If quantity is more than 1, decrement quantity by 1
         if (temp.quantity > 1)
         {
            temp.SubQuantity(1);
         }
         else
         {
            // If only one item exists, find the slot index and clear it
            int RemoveSlotIndex = 0;

            for (int i = 0; i < items.Length; i++)
            {
               if (items[i].item == item)
               {
                  RemoveSlotIndex = i;
                  break;
               }     
            }

            items[RemoveSlotIndex].Clear();
         }
      }
      else
      {
         // If item not found, return false
         return false;
      }

      RefreshUI();
      return true;
   }

   public bool Remove(ItemClass item, int quantity)
   {
      SlotClass temp = Contains(item);

      if (temp != null)
      {
         if (temp.quantity > 1)
         {
            temp.SubQuantity(quantity);
         }
         else
         {
            int RemoveSlotIndex = 0;

            for (int i = 0; i < items.Length; i++)
            {
               if (items[i].item == item)
               {
                  RemoveSlotIndex = i;
                  break;
               }     
            }

            items[RemoveSlotIndex].Clear();
         }
      }
      else
      {
         return false;
      }

      RefreshUI();
      return true;
   }

   private void HotbarSelectorPosition()
   {
      hotbarSelector.transform.position = hotbarSlots[currentSlotIndex].transform.position;
      currentItem = items[currentSlotIndex + (hotbarSlots.Length * 3)].item;
   }

   private void InputHandler()
   {
      if (Input.GetKeyDown(KeyCode.Q))
      {
         craftingShowing = !craftingShowing;
         craftingUI.SetActive(!craftingUI.activeSelf);
         ScrollBarUI.SetActive(!ScrollBarUI.activeSelf);
      }
      else if (Input.GetMouseButtonDown(0))
      {
         if (isItemMoving)
         {
            EndItemMove();
         }
         else
         {
            StartItemMove();
         }
      }
      else if (Input.GetMouseButtonDown(1))
      {
         if (isItemMoving)
         {
            EndItemMoveSingle();
         }
         else
         {
            StartItemMoveHalf();
         }
      }
   }

   // Initialises inventory slots and items array
   private void InitialiseSlots()
   {
      slots = new GameObject[slotHolder.transform.childCount];
      items = new SlotClass[slots.Length];
      hotbarSlots = new GameObject[hotbarSlotHolder.transform.childCount];

      // Populate hotbar slots array
      for (int i = 0; i < hotbarSlots.Length; i++)
      {
         hotbarSlots[i] = hotbarSlotHolder.transform.GetChild(i).gameObject;
      }

      // Initialise items array with empty slots
      for (int i = 0; i < items.Length; i++)
      {
         items[i] = new SlotClass();
      }

      // Populate slots array with slot game objects
      for (int i = 0; i < slotHolder.transform.childCount; i++)
      {
         slots[i] = slotHolder.transform.GetChild(i).gameObject;
      }
   }

   // Adds starting items to the players inventory
   private void StartingItems()
   {
      for (int i = 0; i < startingItems.Length; i++)
      {
         Add(startingItems[i].item, startingItems[i].quantity);
      }
   }

   // Updates the UI to the current state of the inventory
   public void RefreshUI()
   {
      // For each slot in the inventory
      for (int i = 0; i < slots.Length; i++)
      {
         try 
         {
            // Update item icon
            slots[i].transform.GetChild(0).GetComponent<Image>().enabled = true;
            slots[i].transform.GetChild(0).GetComponent<Image>().sprite = items[i].item.itemIcon[0];

            // Update item quantity (if it is stackable)
            if (items[i].item.isStackable)
            {
               slots[i].transform.GetChild(1).GetComponent<Text>().text = items[i].quantity + "";
            }  
            else
            {
               slots[i].transform.GetChild(1).GetComponent<Text>().text = "";   
            }
         }
         catch
         {
            // Handle empty slots
            slots[i].transform.GetChild(0).GetComponent<Image>().sprite = null;
            slots[i].transform.GetChild(0).GetComponent<Image>().enabled = false;
            slots[i].transform.GetChild(1).GetComponent<Text>().text = "";
         }
      }

      // Update hotbarUI
      RefreshHotbar();
   }

   // Updates the hotbarUI to the current state of the hotbar
   public void RefreshHotbar()
   {
      // For each slot in the hotbar
      for (int i = 0; i < hotbarSlots.Length; i++)
      {
         try 
         {
            // Update hotbar item icon
            hotbarSlots[i].transform.GetChild(0).GetComponent<Image>().enabled = true;
            hotbarSlots[i].transform.GetChild(0).GetComponent<Image>().sprite = items[i + (hotbarSlots.Length * 3)].item.itemIcon[0];
            
            // Update item quantity (if it is stackable)
            if (items[i + (hotbarSlots.Length * 3)].item.isStackable)     
            {
               hotbarSlots[i].transform.GetChild(1).GetComponent<Text>().text = items[i + (hotbarSlots.Length * 3)].quantity + "";
            } 
            else
            {
               hotbarSlots[i].transform.GetChild(1).GetComponent<Text>().text = "";
            }
         }
         catch
         {
            // Handle empty slots
            hotbarSlots[i].transform.GetChild(0).GetComponent<Image>().sprite = null;
            hotbarSlots[i].transform.GetChild(0).GetComponent<Image>().enabled = false;
            hotbarSlots[i].transform.GetChild(1).GetComponent<Text>().text = "";
         }
      }
   }

   // Updates the current slot index, Which is needed for HotbarSelectorPosition()
   public void UpdateCurrentSlotIndex(bool newIndex)
   {
      if (newIndex) //True meaning it went up(Scroll up)
      {
         currentSlotIndex++;

         if (currentSlotIndex > 4)
         {
            currentSlotIndex = 0;
         }
      }
      else  //False meaning it went down(Scroll down)
      {
         currentSlotIndex--;

         if (currentSlotIndex < 0)
         {
            currentSlotIndex = 4;
         }
      }
   }

   // For consumables
   public void UseSelected()
   {
      items[currentSlotIndex + (hotbarSlots.Length * 3)].SubQuantity(1);
      RefreshUI();
   }

   // Checks if the inventory is full for the given item and quantity.
   public bool isFull(ItemClass item, int quantity)
   {
      for (int i = 0; i < items.Length; i++)
      {
         // If the slot is empty or adding the quantity doesn't exceed the stack size
         if (items[i].item == null || (items[i].item == item && (items[i].quantity + quantity) <= 64))
         {
            return false;
         }
      }

      // If all slots are full
      return true;
   }

   // Crafts an item using the given a crafting recipe
   public void Craft(CraftingRecipeClass recipe)
   {
      if (recipe.canCraft(this))
      {
         recipe.Craft(this);
      }
      else
      {
         Debug.Log("Cant craft that item!");
      }
   }

   // Checks if the inventory contains the specified item and has space to add more of it.
   public SlotClass Contains(ItemClass item)
   {
      for (int i = 0; i < items.Length; i++)
      {  
         if (items[i].item == item && items[i].quantity != 64)
         {
            return items[i];
         }
      }

      return null;
   }

   // Checks if the inventory contains the specified item with the given quantity or more.
   public bool Contains(ItemClass item, int quantity)
   {
      for ( int i = 0; i < items.Length; i++)
      {
         if (items[i].item == item && items[i].quantity >= quantity)
         {
            return true;
         }
      }

      return false;
   }
   #endregion

   #region Inventory Cursor

   // Controls the appearance and position of the item cursor.
   private void ItemCursor()
   {
      // Set the cursor active based on whether an item is being moved
      itemCursor.SetActive(isItemMoving);

      // Update the cursor's position to match the mouse position
      itemCursor.transform.position = Input.mousePosition;
      
      // If an item is being moved, set the cursors sprite to the icon of the item
      if (isItemMoving)
      {
         itemCursor.GetComponent<Image>().sprite = slotMoving.item.itemIcon[0];
      }
   }
   
   // Initiates moving an item from the original slot to the cursor.
   private bool StartItemMove()
   {
      // Get the closest slot to the cursor
      originalSlot = GetClosestSlot();

      // If the slot is empty or doesn't contain an item, return false
      if (originalSlot == null || originalSlot.item == null)
      {
         return false;
      }
      
      slotMoving = new SlotClass(originalSlot); // Copy of the original slot
      originalSlot.Clear(); // Clears the original slot
      isItemMoving = true;  // Flags that there is a item moving
      RefreshUI();          // Updates the UI
      return true;          // Moving item
   }

   // Initiates moving half of an item stack from the original slot to the cursor
   private bool StartItemMoveHalf()
   {
      // Get the closest slot to the cursor
      originalSlot = GetClosestSlot();

      // If the slot is empty or doesn't contain an item, return false
      if (originalSlot.item == null || originalSlot == null)
      {
         return false;
      }
      
      // Copy half of the original item stack to the cursor slot and removes half from the original slot
      slotMoving = new SlotClass(originalSlot.item, Mathf.CeilToInt(originalSlot.quantity / 2f));
      originalSlot.SubQuantity(Mathf.CeilToInt(originalSlot.quantity / 2f));

      // If the original slot is empty after subtracting, clear it
      if (originalSlot.quantity == 0)
      {
         originalSlot.Clear();
      }

      isItemMoving = true;  // Flags that there is a item moving
      RefreshUI();          // Updates the UI
      return true;          // Moving item
   }

   // Completes the item move process
   private bool EndItemMove()
   {
      // Get the closest slot to the cursor
      originalSlot = GetClosestSlot();
      
      // If no slot is found, add the item back into the inventory
      if (originalSlot == null)
      {
         Add(slotMoving.item, slotMoving.quantity);
         slotMoving.Clear();
      }
      else
      {  
         // If the original slot is not empty.
         if (originalSlot.item != null)
         {
            // If the original slot contains the same stackable item and has space for more.
            if(originalSlot.item == slotMoving.item && originalSlot.item.isStackable && originalSlot.quantity < originalSlot.item.stackSize)
            {
               // Math Example
               var quantityCanAdd = originalSlot.item.stackSize - originalSlot.quantity; // 64 - 20 = 44
               var quantityToAdd = Mathf.Clamp(slotMoving.quantity, 0, quantityCanAdd);  // Mathf.Clamp(50, 0, 44) = 44
               
               var remainder = slotMoving.quantity - quantityToAdd;                      // 50 - 44 = 6

               // Add the calculated quantity to the original slot
               originalSlot.AddQuantity(quantityToAdd);

               // If there is no remainder, clear the moving slot, otherwise update the cursor slot.
               if (remainder == 0)
               {
                  slotMoving.Clear();
               } 
               else
               {
                  slotMoving.SubQuantity(quantityToAdd);
                  RefreshUI();
                  return false;
               }
            }
            else
            {
               // Swap items between original slot and cursor slot.
               tempSlot = new SlotClass(originalSlot); // a = b
               originalSlot.AddItem(slotMoving.item, slotMoving.quantity); // b = c
               slotMoving.AddItem(tempSlot.item, tempSlot.quantity); // a = c
               RefreshUI();
               return true;
            }
         }
         else 
         {
            // Add item from cursor slot to the original slot.
            originalSlot.AddItem(slotMoving.item, slotMoving.quantity);
            slotMoving.Clear();
         }
      }

      // Reset the item moving flag and update the UI.
      isItemMoving = false;
      RefreshUI();
      return true;
   }

   private bool EndItemMoveSingle()
   {
      // Get the closest slot to the cursor
      originalSlot = GetClosestSlot();
      if (originalSlot == null)
      {
         return false;
      }

      // Check if the original slot can receive the item
      if (originalSlot.item != null && (originalSlot.item != slotMoving.item || originalSlot.quantity >= originalSlot.item.stackSize))
      {
         return false;
      }

      // Increment quantity if the item in the original slot matches the item in slotMoving
      if (originalSlot.item != null && originalSlot.item == slotMoving.item)
      {
         originalSlot.AddQuantity(1);
      }
      else
      {
         // Add the item to the original slot with a quantity of 1
         originalSlot.AddItem(slotMoving.item, 1);
      }

      // Decrease the quantity of the item in slotMoving
      slotMoving.SubQuantity(1);

      // If the quantity in slotMoving is less than 1, end the item movement and clear slotMoving
      if (slotMoving.quantity < 1)
      {
         isItemMoving = false;
         slotMoving.Clear();
      }
      else
      {
         isItemMoving = true;
      }
      RefreshUI();
      return true;
   }

   // Finds the closest slot to the current mouse position
   private SlotClass GetClosestSlot()
   {
      for (int i = 0; i < slots.Length; i++)
      {
         // Calculate the distance between the slot position and the mouse position
         if (Vector2.Distance(slots[i].transform.position, Input.mousePosition) <= 32)
         {
            return items[i];
         }
      }

      // If no slot is found within, return null
      return null;
   }
   #endregion

}