using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;
using Ink.Runtime;

public class DialogueManager : MonoBehaviour
{

   [Header("Dialogue Ui")]
   //Refrence to dialogue panel GameObject in Unity scene
   [SerializeField] private GameObject dialgouePanel; 
   //Refrence to TextMeshProUGUI component for text UI
   [SerializeField] private TextMeshProUGUI dialogueText; 

   [Header("Choices UI")]
   //GameObject for buttons in Unity Scene
   [SerializeField] private GameObject[] choices;
   //Text for buttons 
   private TextMeshProUGUI[] choicesText;
   //Current Ink Story - narrative strucutre and content written in ink
   private Story currentStory;
   //Flag for if dialogue is currently active
   public bool dialogueIsPlaying;

   private static DialogueManager instance;

   private void Awake()
   {
      if(instance != null)
      {
         Debug.LogWarning("Found more than one Dialogue Manager in the scene");
      }
      instance = this;
   }

   public static DialogueManager GetInstance()
   {
      return instance;
   }

   private void Start()
   {
      //Dialogue and panel initially false
      dialogueIsPlaying = false;
      dialgouePanel.SetActive(false);
      //Length of choices
      choicesText = new TextMeshProUGUI[choices.Length];
      int index = 0;
      //Get TextMeshProUGUI text for each choice
      foreach (GameObject choice in choices)
      {
         choicesText[index] = choice.GetComponentInChildren<TextMeshProUGUI>();
         index++;
      }
   }

   private void Update()
   {
      if (!dialogueIsPlaying)
      {
         return;
      }

      if (currentStory.currentChoices.Count == 0 && Input.GetKeyDown(KeyCode.T))
      {
         ContinueStory();
      }
   }

   public void EnterDialogueMode(TextAsset inkJSON)
   {
      //New Ink story created 
      currentStory = new Story(inkJSON.text);
      dialogueIsPlaying = true;
      dialgouePanel.SetActive(true);
      
      ContinueStory();
   }

   private IEnumerator ExitDialogueMode()
   {
      //Delay on exit
      yield return new WaitForSeconds(0.2f);
      dialogueIsPlaying = false;
      dialgouePanel.SetActive(false);
      dialogueText.text = "";
   }

   private void ContinueStory()
   {
      //Check if story can continue
      if (currentStory.canContinue)
      {
         dialogueText.text = currentStory.Continue();
         DisplayChoices();
      }
      else
      {
         StartCoroutine(ExitDialogueMode());
      }
   }

   private void DisplayChoices()
   {
      List<Choice> currentChoices = currentStory.currentChoices;

      if(currentChoices.Count > choices.Length)
      {
         Debug.LogError("More choices were given than the UI can support. Number of choices given: " + currentChoices);
      }
      //Loops through in order to display button choice name
      int index = 0;
      foreach(Choice choice in currentChoices)
      {
         choices[index].gameObject.SetActive(true);
         choicesText[index].text = choice.text;
         index++;
      }
      for (int i = index; i < choices.Length; i++)
      {
         choices[i].gameObject.SetActive(false);
      }
   }

   public void MakeChoice(int choiceIndex)
   {
      currentStory.ChooseChoiceIndex(choiceIndex);
      ContinueStory();    
   }
}