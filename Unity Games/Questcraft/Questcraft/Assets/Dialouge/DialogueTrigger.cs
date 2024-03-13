using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DialogueTrigger : MonoBehaviour
{
   //Refrences to GameObject UI visual cue and text from inkJSON
   [Header("Visual Cue")]
   [SerializeField] private GameObject visualCue;

   [Header("Ink JSON")]
   [SerializeField] private TextAsset inkJSON;


   private bool playerInRange;
   private void Awake()
   {
      playerInRange = false;
      visualCue.SetActive(false);
   }

   private void Update()
   {
      //If player is in range & no current ongoing dialogue, show visual cue
      if(playerInRange && !DialogueManager.GetInstance().dialogueIsPlaying)
      {
         visualCue.SetActive(true);
         //Input for triggering dialogue
         if(Input.GetKeyDown(KeyCode.T))
         {
            DialogueManager.GetInstance().EnterDialogueMode(inkJSON);
         }        
      }
      else
      {
         visualCue.SetActive(false);
      }
   }
   //Checks for if another collider enters trigger area
   private void OnTriggerEnter2D(Collider2D collider)
   {
      //Checks if tag = player
      if(collider.gameObject.tag =="Player")
      {
         playerInRange = true;
      }
   }

   private void OnTriggerExit2D(Collider2D collider)
   {
      if(collider.gameObject.tag == "Player")
      {
         playerInRange = false;
      }
   }
}


