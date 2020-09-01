using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;
using Photon.Pun;
using UnityEngine.UI;
public class CheckPhone : MonoBehaviourPunCallbacks
{
    public Transform npcSmartPhoneArea;
    GameObject smartphoneChatUI;
    public Material[] smartPhoneOffMat;
    public Material[] smartPhoneOnMat;
    private void Start()
    {
        if (!photonView.IsMine)
        {
            gameObject.GetComponent<CheckPhone>().enabled = false;
        }
        else
        {
            npcSmartPhoneArea = GameObject.Find("SmartPhoneArea").transform;
            smartphoneChatUI = GameObject.Find("smartphoneChatUI") as GameObject;
            //smartphoneChatUI.SetActive(false);
        }
    }
    private void OnTriggerEnter(Collider other) {
        if(photonView.IsMine)
        {
            if(other.gameObject.name == "SmartPhoneArea") {
                Debug.Log("SmartPhoneArea");
            }
            else if(other.gameObject.name == "SmartPhone") {
                Debug.Log(other.gameObject.name);
                other.gameObject.GetComponent<Renderer>().materials = smartPhoneOnMat;
                smartphoneChatUI.SetActive(true);
            }
        }
    }
    private void OnTriggerExit(Collider other) {
        if (photonView.IsMine)
        {
            if (other.gameObject.name == "SmartPhone")
            {
                Debug.Log("SmartPhoneExit");
                other.gameObject.GetComponent<Renderer>().materials = smartPhoneOffMat;
                smartphoneChatUI.SetActive(false);
            }
        }
    }
}
