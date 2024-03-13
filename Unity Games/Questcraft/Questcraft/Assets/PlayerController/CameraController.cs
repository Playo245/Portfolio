using System.Collections;
using UnityEngine;

public class CameraController : MonoBehaviour
{
   //Adjust how fast camera goes to player
   [Range(0,1)]
   public float smoothTime;
   
   [HideInInspector]
   public int world;

   private float ortho; 
   //Transform from Unity = position, Players position
   public Transform playerTransform;
   //Set camera at spawn
   public void Spawn(Vector3 pos)
   {
      GetComponent<Transform>().position = pos;
      ortho = GetComponent<Camera>().orthographicSize;
   }

   public void FixedUpdate()
   {
      //Current Cam position
      Vector3 pos = GetComponent<Transform>().position;
      //Unity built .Lerp, interpolates camera position bewween value a and b toward Player
      pos.x = Mathf.Lerp(pos.x, playerTransform.position.x, smoothTime);
      pos.y = Mathf.Lerp(pos.y, playerTransform.position.y, smoothTime);
      //Unity built .Clamp, Camera stays within world boundaries
      pos.x = Mathf.Clamp(pos.x, 0 + (ortho * 1.78f), world - (ortho * 1.88f));
      pos.y = Mathf.Clamp(pos.y, 0 + (ortho), world - (ortho));
      
      //Updates position
      GetComponent<Transform>().position = pos;
   }
}
