using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Photon.Pun;

public class MakeBackSound : MonoBehaviour
{
    private void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.tag == "Player")
        {
            if (GameObject.Find("SoundManager(Clone)") == null)
                PhotonNetwork.Instantiate("SoundManager", new Vector3(0, -424, 448), Quaternion.identity);
        }
    }
}
