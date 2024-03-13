using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class NpcController : MonoBehaviour
{
    public bool onGround;

    private void OnTriggerStay2D(Collider2D col)
    {
        if (col.CompareTag("Ground"))
            onGround = true;
    }

    private void OnTriggerExit2D(Collider2D col)
    {
        if (col.CompareTag("Ground"))
            onGround = false;
    }

    // Add a public method to check if the NPC is on the ground
    public bool IsOnGround()
    {
        return onGround;
    }
}
